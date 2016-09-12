package com.nd.sdp.android.app;

import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    String dictPath = "/myspell/en_US.dic";
    String affPath = "/myspell/en_US.aff";

    MySpell mMySpell;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

    private void init() {
        String sdcardPath = Environment.getExternalStorageDirectory().getPath();
        mMySpell = new MySpell(sdcardPath+dictPath, sdcardPath+affPath);
    }

    public void onSpell(View view) {
        init();
        System.out.println(mMySpell.getCheck("food"));
        String[] suggestions = mMySpell.getSuggestion("foobaz");
        if(suggestions != null && suggestions.length > 0) {
            for(String suggestion : suggestions) {
                System.out.println(suggestion);
            }
        }
    }
}
