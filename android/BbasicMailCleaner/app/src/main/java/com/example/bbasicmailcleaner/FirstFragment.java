package com.example.bbasicmailcleaner;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.navigation.fragment.NavHostFragment;

import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.logging.Logger;

public class FirstFragment extends Fragment {
    private static final String TAG = "MESSAGES_FRAGMENT";
    final String MESSAGES_EXTRA = "MESSAGES_LIST";
    final String MESSAGE_EXTRA_RESULT = "CLEAN_MESSAGE_RESULT";

    ListView lv_messages;
    EditText et_message;
    Button bn_send;
    FloatingActionButton fab_clean;

    ArrayAdapter<String> adapter_messages;

    ArrayList<String> list_messages;
    LinkedList<String> ll_messages;

    @Override
    public View onCreateView(
            LayoutInflater inflater, ViewGroup container,
            Bundle savedInstanceState
    ) {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_first, container, false);
    }

    public void onViewCreated(@NonNull final View view, Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        lv_messages = (ListView) view.findViewById(R.id.lv_messages);
        et_message = (EditText) view.findViewById(R.id.et_message);
        bn_send = (Button) view.findViewById(R.id.bn_send);
        fab_clean = view.findViewById(R.id.fab_clean);

        list_messages = new ArrayList<String>();
        ll_messages = new LinkedList<String>();
        adapter_messages = new ArrayAdapter(getActivity(), R.layout.listview, ll_messages);
        lv_messages.setAdapter(adapter_messages);

        bn_send.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                ll_messages.add(et_message.getText().toString());
                adapter_messages.notifyDataSetChanged();
            }
        });

        fab_clean.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                removeDuplicates(ll_messages);
            }
        });
    }

    @Override
    public void onDestroyView() {
        super.onDestroyView();
        getActivity().stopService(new Intent(getActivity(), MailCleanerService.class));
    }

    @Override
    public void onResume() {
        super.onResume();
        getActivity().registerReceiver(receiver, new IntentFilter(MESSAGE_EXTRA_RESULT));
    }

    @Override
    public void onPause() {
        super.onPause();
        getActivity().unregisterReceiver(receiver);
    }

    private void removeDuplicates(LinkedList<String> list)
    {
        Intent i = new Intent(getActivity(), MailCleanerService.class);
        i.putStringArrayListExtra(MESSAGES_EXTRA, new ArrayList<String>(list));
        getActivity().startService(i);
    }

    BroadcastReceiver receiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            ArrayList<String> clean_messages = intent.getStringArrayListExtra(MESSAGES_EXTRA);
            Log.w(TAG, "BroadcastReceiver.OnReceive()");
            for (String s : clean_messages)
            {
                Log.w(TAG, s);
            }
//
            ll_messages.clear();
            ll_messages.addAll(clean_messages);
            adapter_messages.notifyDataSetChanged();
        }
    };
}
