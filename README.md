![AcquireIO-Lite](https://developers.acquire.io/media/data/acquire-logo.png)

[![CocoaPods](https://img.shields.io/badge/platforms-iOS-orange.svg?maxAge=2592000)](https://cocoapods.org/pods/AcquireIO-Lite)
[![Languages](https://img.shields.io/badge/languages-OjbC%20%7C%20%20Swift-orange.svg?maxAge=2592000)](https://github.com/acquireio/CocoaPods)
[![CocoaPods](https://img.shields.io/cocoapods/v/AcquireIO-Lite.svg?maxAge=2592000)](https://cocoapods.org/pods/AcquireIO-Lite)
[![Apache License](http://img.shields.io/badge/license-APACHE2-blue.svg?style=flat)](https://www.apache.org/licenses/LICENSE-2.0.html)
[![CocoaPods](https://img.shields.io/cocoapods/dt/AcquireIO-Lite.svg?maxAge=2592000)]()

## Customer Support

👋 This is a repository of Cocoapods which are ad-hoc/beta releases of the AcquireIO-Lite frontend bundle iOS SDK. 

## Installation

AcquireIO for iOS supports iOS 8, iOS 9, iOS 10, iOS 11, iOS 12 and iOS 13. 

Building with Xcode 9+ is required, which adds support for iPhone X and iOS 11.

Building with XCode 11.4+ and Swift 5.2.2 is required for Swift.

### CocoaPods

### [Add Private pod to your Podfile](https://guides.cocoapods.org/making/private-cocoapods.html)

Add the AcquireIO-Lite pod into your Podfile and run `pod install`.

    target :YourTargetName do
      pod 'AcquireIO-Lite'
    end
    
Note: Since iOS 10, it's mandatory to add before you access privacy-sensitive data like Camera, and so on, you must ask for the authorization, or your app will crash when you access them.

Open the file in your project named `info.plist`, right click it, opening as Source Code, paste this code below to it. Or you can open  `info.plist` as `Property List` by default, click the add button, Xcode will give you the suggest completions while typing Privacy - with the help of keyboard and 

Remember to write your description why you ask for this authorization, between  `<string>` and `</string>`, or your app will be rejected by apple:

```
<!-- Camera -->
<key>NSCameraUsageDescription</key>
<string>$(PRODUCT_NAME) use camera for video chat</string>

<!-- Photo Library -->
<key>NSPhotoLibraryUsageDescription</key>
<string>$(PRODUCT_NAME) send photo/video to agent</string>

```

## Setup and Configuration
* Our [installation guide](https://developer.acquire.io/sdk/ios) contains full setup and initialisation instructions.

## License

AcquireIO-Lite Cocoapods are distributed under [Apache License, Version 2.0](http://www.apache.org/licenses/LICENSE-2.0.html).

## Help

If you have any questions or comments, you can reach us at developer@acquire.io

