package com.example.bbasicmailcleaner;

import android.app.Service;
import android.content.Intent;
import android.os.Bundle;
import android.os.IBinder;
import android.util.Log;

import androidx.annotation.Nullable;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;

public class MailCleanerService extends Service {
    private final static String TAG = "MAIL_CLEANER_SERVICE";
    final String MESSAGES_EXTRA = "MESSAGES_LIST";
    final String MESSAGE_EXTRA_RESULT = "CLEAN_MESSAGE_RESULT";
    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        Log.w(TAG, "OnStartCommand()");
        LinkedList<String> messages = new LinkedList<String>(intent.getStringArrayListExtra(MESSAGES_EXTRA));
        removeDuplicates(messages);
        Intent result = new Intent(MESSAGE_EXTRA_RESULT);
        result.putStringArrayListExtra(MESSAGES_EXTRA, new ArrayList<String>(messages));
        sendBroadcast(result);
        return Service.START_NOT_STICKY;
    }

    @Override
    public void onCreate() {
        super.onCreate();
        Log.i(TAG, "OnCreate()");
    }

    private void removeDuplicates(LinkedList<String> list)
    {
        Map<String, Integer> count_map = new HashMap<>();
        Log.e(TAG, "removeDuplicates");
        Iterator<String> iterator = list.iterator();
        while (iterator.hasNext()) {
            String value = iterator.next();
            if (count_map.containsKey(value))
            {
                count_map.replace(value, count_map.get(value) + 1);
                iterator.remove();
            }
            else
            {
                count_map.put(value, 1);
            }
            Log.w(TAG, value);
        }

        for (String key : count_map.keySet())
        {
            Log.w(TAG, key + ": " + count_map.get(key));
        }
    }
}
