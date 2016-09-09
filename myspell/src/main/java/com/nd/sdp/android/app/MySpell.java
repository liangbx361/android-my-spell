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

    static {
        System.loadLibrary("myspell");
    }

    public native void init(String dicPath, String affPath);

    public native String[] check(String words);

    public native String[] checkAndSuggestion(String words);

    public native String[] suggestion(String words);
}
