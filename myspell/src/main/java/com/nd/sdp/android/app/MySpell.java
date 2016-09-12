package com.nd.sdp.android.app;

/**
 * <p>Title: <／p>
 * <p>Description: <／p>
 * <p>Copyright: Copyright (c) 2016<／p>
 * <p>Company: NetDragon<／p>
 *
 * @author liangbx
 * @version 2016/9/9
 */
public class MySpell {

    public MySpell(String dicPath, String affPath) {
        init(dicPath, affPath);
    }

    public String[] getSuggestion(String word) {
        return suggestion(word);
    }

    public boolean getCheck(String word) {
        return check(word);
    }

    static {
        System.loadLibrary("myspell");
    }

    public native void init(String dicPath, String affPath);

    public native boolean check(String word);

    public native String[] suggestion(String word);

}
