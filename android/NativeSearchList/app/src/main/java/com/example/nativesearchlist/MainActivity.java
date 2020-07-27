package com.example.nativesearchlist;

import androidx.appcompat.app.AppCompatActivity;

import android.app.SearchManager;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.SearchView;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private static final String TAG = "MainActivity";

    ListView listView;
    TextView textView;
    SearchView searchView;

    ArrayList<String> wordsDB = new ArrayList<String>();
    ArrayList<String> searchResult = new ArrayList<String>();
    ArrayAdapter<String> adapter;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        InitWordDB();

        listView = (ListView) findViewById(R.id.listView);
        textView = (TextView) findViewById(R.id.textView);
        searchView = (SearchView) findViewById(R.id.searchView);

        // Example of a call to a native method
        searchResult.add(getString(R.string.empty_search_result));
        adapter = new ArrayAdapter(this, R.layout.listview, searchResult);
        listView.setAdapter(adapter);

        // Get the SearchView and set the searchable configuration
        SearchManager searchManager = (SearchManager) getSystemService(Context.SEARCH_SERVICE);
        // Assumes current activity is the searchable activity
        searchView.setSearchableInfo(searchManager.getSearchableInfo(getComponentName()));
        searchView.setIconifiedByDefault(false); // Do not iconify the widget; expand it by default

        searchView.setOnQueryTextListener(new SearchView.OnQueryTextListener() {
            @Override
            public boolean onQueryTextSubmit(String query) {
                Log.w(TAG, "Query string: " + query);
                ArrayList<String> result = Search(query.toLowerCase());
                if (result.isEmpty())
                    result.add(getResources().getString(R.string.empty_search_result));
                searchResult.clear();
                searchResult.addAll(result);
                adapter.notifyDataSetChanged();
                return false;
            }

            @Override
            public boolean onQueryTextChange(String s) {
                return false;
            }
        });
    }

    private void InitWordDB()
    {
        wordsDB.add("you");
        wordsDB.add("probably");
        wordsDB.add("despite");
        wordsDB.add("moon");
        wordsDB.add("misspellings");
        wordsDB.add("pale");
        wordsDB.add("cesar");
    }

    private ArrayList<String> Search(String query)
    {
        ArrayList<String> result = new ArrayList<String>();
        for (String s : wordsDB)
        {
            if(IsPartialPermutation(query, s) ^ IsTypo(query, s)) result.add(s);
        }
        return result;
    }

    /**
     * Verifies if two string are a partial permutation. It consider a partial permutation if:
     * - The first letter hasn't change place;
     * - If word has more than 3 letters, up to 2/3 of the letters have changed place.
     * @param str1 First string.
     * @param str2 Second string.
     * @return True if str2 is a partial permutation of str1. False, otherwise.
     */
    public native boolean IsPartialPermutation(String str1, String str2);

    /**
     * Given two strings, it checks if they are one typo (or zero typos) away. Verifies if a string
     * is a result of a typo that was applied to another given string. There are three types of
     * typos that can be performed on strings: insert a character, remove a character, or
     * replace a character.
     * @param str1 First string.
     * @param str2 Second string.
     * @return True if str2 is one or zero typo away from str1. False, otherwise.
     */
    public native boolean IsTypo(String str1, String str2);
}
