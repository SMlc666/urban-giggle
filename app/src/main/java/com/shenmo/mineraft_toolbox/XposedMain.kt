package com.shenmo.mineraft_toolbox

import android.app.Activity
import android.util.Log
import com.shenmo.mineraft_toolbox.instance.instance
import de.robv.android.xposed.IXposedHookLoadPackage
import de.robv.android.xposed.XC_MethodHook
import de.robv.android.xposed.XposedHelpers
import de.robv.android.xposed.callbacks.XC_LoadPackage

class XposedMain  : IXposedHookLoadPackage {
    override fun handleLoadPackage(lpparam: XC_LoadPackage.LoadPackageParam) {
        lpparam.appInfo.packageName.let {
             Log.d("ToolBox", "handleLoadPackage: $it")
            if (it == "com.mojang.minecraftpe") {
                XposedHelpers.findAndHookMethod(
                    "com.mojang.minecraftpe.MainActivity",
                    lpparam.classLoader,
                    "onCreate",
                    object : XC_MethodHook() {
                        override fun afterHookedMethod(param: MethodHookParam) {
                            super.afterHookedMethod(param)
                            Log.d("ToolBox", "MainActivity onCreate")

                            // 获取当前 Activity 的上下文
                            val activity = param.thisObject as Activity
                            // 创建并显示 AlertDialog
                            AlertDialog.Builder(activity)
                                .setTitle("ToolBox")
                                .setMessage("MinecraftPE")
                                .setPositiveButton("确定") { dialog, _ ->
                                    dialog.dismiss()
                                }
                                .show()

                            Log.d("ToolBox", "AlertDialog shown")
                        }
                    })
                Log.d("ToolBox", "find MinecraftPE")
                System.loadLibrary("mineraft_toolbox")
                Log.d("ToolBox", "load mineraft_toolbox library")
                val Instance = instance(
                )
                val manager = Instance.getManager()
                Log.d("ToolBox", "manager: $manager")
            }
        }
    }
}
