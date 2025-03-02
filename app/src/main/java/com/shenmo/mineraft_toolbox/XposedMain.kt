package com.shenmo.mineraft_toolbox

import android.util.Log
import de.robv.android.xposed.IXposedHookLoadPackage
import de.robv.android.xposed.callbacks.XC_LoadPackage

class XposedMain  : IXposedHookLoadPackage {
    override fun handleLoadPackage(lpparam: XC_LoadPackage.LoadPackageParam) {
        lpparam.appInfo.packageName.let {
             Log.d("ToolBox", "handleLoadPackage: $it")
            if (it == "com.mojang.minecraftpe") {
                Log.d("ToolBox", "find MinecraftPE")
                System.loadLibrary("mineraft_toolbox")
                Log.d("ToolBox", "load mineraft_toolbox library")
            }
        }
    }
}