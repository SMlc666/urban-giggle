package com.shenmo.mineraft_toolbox

import android.util.Log
import de.robv.android.xposed.IXposedHookLoadPackage
import de.robv.android.xposed.callbacks.XC_LoadPackage

class XposedMain  : IXposedHookLoadPackage {
    override fun handleLoadPackage(lpparam: XC_LoadPackage.LoadPackageParam) {
        lpparam.appInfo.packageName.let {
             Log.d("XposedMain", "handleLoadPackage: $it")
            if (it == "com.mojang.minecraftpe") {
                Log.d("XposedMain", "find MinecraftPE")
                System.loadLibrary("mineraft_toolbox")
                Log.d("XposedMain", "load mineraft_toolbox library")
            }
        }
    }
}