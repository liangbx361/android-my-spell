package com.nd.sdp.android.myspell;

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
        initNative(dicPath, affPath);
    }

    public String[] getSuggestion(String word) {
        return suggestionNative(word);
    }

    public boolean getCheck(String word) {
        return checkNative(word);
    }

    static {
        System.loadLibrary("myspell");
    }

    private native void initNative(String dicPath, String affPath);

    private native boolean checkNative(String word);

    private native String[] suggestionNative(String word);

}
