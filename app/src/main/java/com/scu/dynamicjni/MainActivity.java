package com.scu.dynamicjni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{

    static {
        System.loadLibrary("hellojni");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        findViewById(R.id.text1).setOnClickListener(this);
        findViewById(R.id.test2).setOnClickListener(this);
    }
    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.text1:
                new HelloJNI().printHello();
              //  HelloJNI.printString("ceshi");
                break;
            case R.id.test2:

                break;
        }
    }
}
