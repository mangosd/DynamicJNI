package com.scu.dynamicjni;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class PStestActivity extends Activity {

    private TextView text;
    List<String>psinfos = new ArrayList<String>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pstest);
        text = (TextView)findViewById(R.id.mytest);
        findViewById(R.id.btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                isProcessRunningB21("test");
                StringBuilder sb = new StringBuilder();
                for (int i=0;i<psinfos.size();i++){
                    sb.append(psinfos.get(i)+"\n");
                }
                text.setText(sb.toString());
            }
        });
    }


    private static boolean isProcessRunningL21(Context context, String processName) {
        ActivityManager activityManager = (ActivityManager) context.getSystemService(Context.ACTIVITY_SERVICE);
        List<ActivityManager.RunningAppProcessInfo> procInfos = activityManager.getRunningAppProcesses();
        if (procInfos == null) {
            return false;
        }
        for (int i = 0; i < procInfos.size(); i++) {
            if (procInfos.get(i).processName.equals(processName)) {
                return true;
            }
        }
        return false;
    }

    private boolean isProcessRunningB21(String processName) {
        BufferedReader input = null;
        Process p = null;
        try {
            String line;
            p = Runtime.getRuntime().exec("ps");
            input = new BufferedReader(new InputStreamReader(p.getInputStream()));
            while ((line = input.readLine()) != null) {
                psinfos.add(line);
//                if (line.trim().endsWith(processName)) {
//                    return true;
//                }
            }

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (input != null) {
                try {
                    input.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (p != null) {
                p.destroy();
            }
        }

        return false;
    }

//    private static boolean isProcessRunning(Context context, String processName) {
//        int curSdkVersion = android.os.Build.VERSION.SDK_INT;
//        if (curSdkVersion < 21) {
//            return isProcessRunningL21(context, processName);
//        } else {
//            return isProcessRunningB21(processName);
//        }
//    }

}
