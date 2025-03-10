plugins {
    alias(libs.plugins.android.application)
    alias(libs.plugins.kotlin.android)
    alias(libs.plugins.compose.compiler)
    id("com.google.devtools.ksp") version "2.0.0-1.0.24"
}

android {
    namespace = "com.shenmo.mineraft_toolbox"
    compileSdk = 35

    defaultConfig {
        applicationId = "com.shenmo.mineraft_toolbox"
        minSdk = 29
        targetSdk = 35
        versionCode = 1
        versionName = "1.0"

        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
        externalNativeBuild {
            ndk{
                abiFilters.add("arm64-v8a")
            }
            cmake {

            }
        }
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
        }
        debug {
            externalNativeBuild {
                cmake {
                    cppFlags.add("-g")
                    cFlags.add("-g")
                    cppFlags.add("-D_DEBUG_")
                    cFlags.add("-D_DEBUG_")
                }
            }
        }
        release {
            externalNativeBuild {
                cmake {
                    cppFlags.add("-O3")
                    cFlags.add("-O3")
                }
            }
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_17
        targetCompatibility = JavaVersion.VERSION_17
    }
    kotlinOptions {
        jvmTarget = "17"
    }
    externalNativeBuild {
        cmake {
            path = file("src/main/cpp/CMakeLists.txt")
            version = "3.31.5"
        }
    }
    buildFeatures {
        viewBinding = true
        prefab = true
        compose = true
    }
}

dependencies {
    implementation(libs.androidx.core.ktx)
    implementation(libs.androidx.appcompat)
    implementation(libs.material)
    implementation(libs.androidx.constraintlayout)
    testImplementation(libs.junit)
    androidTestImplementation(libs.androidx.junit)
    androidTestImplementation(libs.androidx.espresso.core)
    // compileOnly(files("lib/XposedBridgeAPI-89.jar"))
    implementation(libs.shadowhook)
    //compose
    val composeBom = platform("androidx.compose:compose-bom:2025.02.00")
    implementation(composeBom)
    androidTestImplementation(composeBom)
    implementation("androidx.compose.material3:material3")
    implementation("androidx.compose.ui:ui-tooling-preview")
    debugImplementation("androidx.compose.ui:ui-tooling")
    implementation("androidx.activity:activity-compose:1.10.0")
    //yuki hook
    implementation("com.highcapable.yukihookapi:api:1.2.1")
    // 作为 Xposed 模块使用务必添加，其它情况可选
    compileOnly("de.robv.android.xposed:api:82")
    // 作为 Xposed 模块使用务必添加，其它情况可选
    ksp("com.highcapable.yukihookapi:ksp-xposed:1.2.1")
}