//
//  AcquireIOClient.h
//  AcquireIOSDK
//
//  Created by Raju Jangid on 1/19/18.
//  Copyright © 2018 AcquireIO Lab. All rights reserved.
//  Version 2.1.1
//



#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// Status for the agent.
typedef NS_ENUM(NSInteger, AcquireIOAgentStatus) {
    /// Online status for agent.
    AcquireIOAgentStatusOnline,
    /// Offline status for agent.
    AcquireIOAgentStatusOffline,
    /// Invisible status for agent.
    AcquireIOAgentStatusInvisible,
};

/// Status for the acquire.io app support session connection.
typedef NS_ENUM(NSInteger, AcquireIOConnectionStatus) {
    /// App support session connection status not connected.
    AcquireIOConnectionStatusNotConnected,
    /// App support session connection status disconnected.
    AcquireIOConnectionStatusDisconnected,
    /// App support session connection status connecting.
    AcquireIOConnectionStatusConnecting,
    /// App support session connection status connected.
    AcquireIOConnectionStatusConnected,
    /// App support session connection status started.
    AcquireIOConnectionStatusSessionStarted,
};


/// Status for the acquire.io app support session connection.
typedef NS_ENUM(NSInteger, AcquireIOPushMessageStatus) {
    /// Unknown status.
    AcquireIOPushMessageStatusUnknown,
    /// New downstream message received by the app.
    AcquireIOPushMessageStatusNew
};

/// Status for the acquire.io app support session connection.
typedef NS_ENUM(NSInteger, AcquireIOAPNSTokenType) {
    /// Unknown token type.
    AcquireIOAPNSTokenTypeUnknown,
    /// Sandbox token type.
    AcquireIOAPNSTokenTypeSandbox,
    /// Production token type.
    AcquireIOAPNSTokenTypeProd,
};

/// Status for the acquire.io app cobrowse session connection.
typedef NS_ENUM(NSInteger, CobrowseSessionStatus) {
    /// App cobrowse session connection status inactive not connected.
    CobrowseSessionStatusInActive,
    /// App cobrowse session connection status connecting.
    CobrowseSessionStatusConnecting,
    /// App cobrowse session connection status waiting for agent.
    CobrowseSessionStatusWaiting,
    /// App cobrowse session connection status active/connected with agent.
    CobrowseSessionStatusActive,
    /// App cobrowse session connection status disconnected.
    CobrowseSessionStatusDisconnected,
};

typedef NS_ENUM(NSInteger, SocketConnectionState) {
    kSocketConnectionStateDisconnected,
    kSocketConnectionStateConnecting,
    kSocketConnectionStateConnected,
    kSocketConnectionStateDeclined,
};

/// Status for the acquire.io app support call video/audio.
typedef NS_ENUM(NSInteger, AcquireIOCallSupportStatus) {
    AcquireIOCallSupportStatusNotConnected,
    AcquireIOCallSupportStatusDisconnected,
    AcquireIOCallSupportStatusConnecting,
    AcquireIOCallSupportStatusConnected,
};

/**
 CallerView Interaction event's enum by akash

 - AcquireIOInteractionEventTypeAudioCallAnswered: when user answer call with audio
 - AcquireIOInteractionEventTypeVideoCallAnswered: when user answer call with video
 - AcquireIOInteractionEventTypeCallDeclined: when user declined call
 - AcquireIOInteractionEventTypeCallerViewMinimize: when user minimize call window
 - AcquireIOInteractionEventTypeCallerViewMaximize: when user maximize call window
 - AcquireIOInteractionEventTypeCallSpeakerOn: when user turn on speaker
 - AcquireIOInteractionEventTypeCallSpeakerOff: when user turn off speaker
 - AcquireIOInteractionEventTypeCallMute: when user turn off mic
 - AcquireIOInteractionEventTypeCallUnmute: when user turn on mic
 - AcquireIOInteractionEventTypeCallVideoOn: when user turn on video
 - AcquireIOInteractionEventTypeCallVideoOff: when user turn off video
 - AcquireIOInteractionEventTypeCallDisconnected: when user disconnect call
 
 @available Available in SDK version 2.0.6 or later
 
 */
typedef NS_ENUM(NSInteger, AcquireIOInteractionEventType) {
    AcquireIOInteractionEventTypeAudioCallStarted,
    AcquireIOInteractionEventTypeVideoCallStarted,
    AcquireIOInteractionEventTypeAudioCallAnswered,
    AcquireIOInteractionEventTypeVideoCallAnswered,
    AcquireIOInteractionEventTypeCallDeclined,
    AcquireIOInteractionEventTypeCallAutoDeclined,
    AcquireIOInteractionEventTypeCallerViewMinimize,
    AcquireIOInteractionEventTypeCallerViewMaximize,
    AcquireIOInteractionEventTypeCallerViewCameraSwitchToFront,
    AcquireIOInteractionEventTypeCallerViewCameraSwitchToBack,
    AcquireIOInteractionEventTypeCallSpeakerOn,
    AcquireIOInteractionEventTypeCallSpeakerOff,
    AcquireIOInteractionEventTypeCallMute,
    AcquireIOInteractionEventTypeCallUnmute,
    AcquireIOInteractionEventTypeCallVideoOn,
    AcquireIOInteractionEventTypeCallVideoOff,
    AcquireIOInteractionEventTypeCallDisconnected,
    AcquireIOInteractionEventTypeConversationStart,
    AcquireIOInteractionEventTypeConversationEnd,
    AcquireIOInteractionEventTypeConversationFeedbackSubmit,
};

/**
 *  Progress block for all types of operations.
 *
 *  @param totalBytesSent           Contains number of bytes already sent to the receiver.
 *  @param totalBytesExpectedToSend Contains overall number of bytes needed to be sent.
 *  In a case if this value is unknown, NSUIntegerMax may be returned.
 */
typedef void (^AIOUploadProgressBlock)(NSUInteger totalBytesSent, NSUInteger totalBytesExpectedToSend);

/**
 *  Completion block for all types of operations.
 *
 *  @param response Response serialized value. May be nil.
 *  @param error    Error object which can contain API-dependent failure information,
 *  or come from Foundation issue, discovered during client request process.
 */
typedef void (^AIOUploadCompletionBlock)(id _Nullable response, NSError * _Nullable error);


@interface AcquireIOConfig : NSObject

/**
 * Return an instance of AcquireIOConfig
 *
 * Call any method of AcquireIOConfig instance you need use shared config object. For example you want to initForAccount for setup
 * account then you call as [AcquireIO support] setAccount:<AccountUniqueID>
 *
 * @Available Available in SDK 1.0.0 version or later
 */

+ (AcquireIOConfig * _Nonnull) config;

/**
 *  if your app require changes in UI and supported functions to reset default setting with simple dictionary
 *
 *  @param dict NSDictionary of option for support view
 *
 *  Set dictionary key values format: setDict
 */

- (void) setDict:(NSDictionary * _Nonnull)dict;

/**
 *  if your added in ThemeOptions key in AcquireIOConfig
 *  then set useDefaultTheme YES to load default theme setting instead of your
 *  ThemeOptions theme setting
 *
 *  if not set key in config ThemeOptions in your AcquireIOConfig then always load theme default setting
 *
 *  Initialize dictionary key: UseDefaultTheme
 */

@property(nonatomic, assign) BOOL useDefaultTheme; //Default @NO

/**
 *  Default theme option like color before session start, after session start theme color will be change according to your acquire setting. See more to know about theme customization https://goo.gl/FvrtXf
 *
 *  Initialize dictionary key: ThemeOptions
 */

@property(nonatomic, strong) NSDictionary * _Nullable themeOptions; //Default AcquireIO default theme

/**
 *  This is init key for initilize AcquireIO chat with system button bottom right
 *  Set image name should be put in main bundle of app.
 *
 *  Initialize dictionary key: ButtonImageName
 */
@property(nonatomic, assign) NSString * _Nullable buttonImageName;  //Default nil

/**
 *  Share your app screen with agent then show a one pixel red border to show visitor
 *  that your app screen is sharing with app support agent
 *
 *  Initialize dictionary key: ScreenShareBorder
 */
@property(nonatomic, assign) BOOL screenShareBorder;  //Default @YES

/**
 *  Show avatar of agent or visitor in main chat messages screen and available support agents list
 *
 *  Initialize dictionary key: ShowAvatar
 */
@property(nonatomic, assign) BOOL showAvatar; //Default @YES


/**
 *  show list of threads.
 *
 *  Initialize dictionary key: ShowThreadList
 *  @available Available in SDK version 2.0.10 or later
 */

@property(nonatomic, assign) BOOL showThreadList; //Default @YES


/**
 *  Show chat button in right bottom on user's screen and its just hide button but chat functionality will not affect by this option.
 *
 *  Initialize dictionary key: ShowChatButton
 */

@property(nonatomic, assign) BOOL showChatButton; //Default @YES

/**
 *  Show video button in top tab list on visitor's main chat messages screen and its just hide button but video functionality will not affect by this option.
 *
 *  Initialize dictionary key: ShowVideoButton
 */

@property(nonatomic, assign) BOOL showVideoButton; //Default @YES


/**
 *  Show audio button in top tab list on visitor's main chat messages screen and its just hide button but audio functionality will not affect by this option.
 *
 *  Initialize dictionary key: ShowAudioButton
 */

@property(nonatomic, assign) BOOL showAudioButton; //Default @YES

/**
 *  Show in-app notifiction when app state is active state.
 *
 *  Initialize dictionary key: ShowLocalNotificationInApp
 */

@property(nonatomic, assign) BOOL showLocalNotificationInApp; //Default @YES

/**
 *  Show local notifiction when app is in background state.
 *
 *  Initialize dictionary key: ShowLocalNotificationBackgroundState
 */

@property(nonatomic, assign) BOOL showLocalNotificationBackgroundState; //Default @YES


/**
 *  Share your app screen with agent then show sdk stop button, if you not implement your app button.
 *  that will show when your app screen is sharing with app support agent
 *
 *  Initialize dictionary key: ShowDefaultStopButton
 */
@property(nonatomic, assign) BOOL showDefaultStopButton;  //Default @YES


/**
 *  Session will be auto connect to server and start and no need to invoke any additional method for start session. If you set @"SessionConnectAndStartAuto": @NO then you must call [[AcquireIO support] startSession] method to start connection with server.
 *
 *  Initialize dictionary key: SessionConnectAndStartAuto
 */
@property(nonatomic, assign) BOOL sessionConnectAndStartAuto;  //Default @YES

/**
 *  Initilize AcquireIO chat with custom server, Websocket server ip or url to connect support socket server
 *
 *  This is optional, if not set default AcquireIO socket server will connect
 *
 *  Initialize dictionary key: WebSocketServer
 */


@property(nonatomic, assign) NSString * _Nullable webSocketServer; //Default AcquireIO default server

/**
 *  Forcefully remove video call disconnect button to prevent visitor to disconnect with agent.
 *
 *  This is optional, if not set default @NO
 *
 *  Initialize dictionary key: RemoveVideoCallDisconnectButton
 */
@property(nonatomic, assign) BOOL removeVideoCallDisconnectButton;  //Default @NO

/**
 *  Forcefully remove audio call disconnect button to prevent visitor to disconnect with agent.
 *
 *  This is optional, if not set default @NO
 *
 *  Initialize dictionary key: RemoveAudioCallDisconnectButton
 */
@property(nonatomic, assign) BOOL removeAudioCallDisconnectButton;  //Default @NO

/**
 *  Forcefully remove audio call disconnect button to prevent visitor to disconnect with agent.
 *
 *  This is optional, if not set default @NO
 *
 *  Initialize dictionary key: removeCallViewResizeButton
 * @avaialble available in SDK 2.0.12 or later
 */
@property(nonatomic, assign) BOOL removeCallViewResizeButton;  //Default @NO

/**
 *  if yes then user want be able to chat with agents.
 *  if No, User can chat with agnets.
 *
 *  This is optional, if not set default @NO
 *
 *  Initialize dictionary key: isCoBrowseOnly
 *  @Available Available in SDK 2.0.10 version or later
 */
@property(nonatomic, assign) BOOL isCoBrowseOnly;  //Default @NO

/*
 *
 *  if yes then user want be able to upload any attachment in chat.
 *  This is optional, is not set default is @NO
 *  @Available available in SDK 2.0.12 version or later
 */

@property (nonatomic, assign) BOOL disableAttachment;

@end

@protocol AcquireIODelegate;

@interface AcquireIO : NSObject

@property (nonatomic, retain) __nullable id<AcquireIODelegate> delegate  __deprecated_msg("Use addDelegate: method instead.");



/**
 * Return an instance of AcquireIO
 *
 * Call any method of AcquireIO instance you must need use sharedObject. For example you want to initForAccount for setup
 * account then you call as [AcquireIO support] setAccount:<AccountUniqueID>
 *
 * @Available Available in SDK 1.0.0 version or later
 */

+ (AcquireIO * __nonnull) support;


/**
 * Adds a delegate for the Acquire visitor session to receive events.
 *
 * @param delegate     AcquireIODelegate object _required_
 *
 *  @available Available in SDK version 1.0.9 or later
 */
-(void)addDelegate:(id<AcquireIODelegate>  __nonnull) delegate;

/**
 * Removes a delegate for the Acquire visitor session to receive events.
 *
 * @param delegate     AcquireIODelegate object _required_*
 *
 *  @available Available in SDK version 1.0.9 or later
 */
-(void)removeDelegate:(id<AcquireIODelegate> __nonnull) delegate;


/**
 * This is init method for initilize AcquireIO chat
 *
 * Calling initForAccount method you must pass one accountUID parameter.
 * @param accountUID This is your account unique id
 * @param optionDictionary is a dict for additional detail.
 *
 * @Available Available in SDK version 1.0.0 or later
 */

- (void)setAccount:(NSString * __nonnull)accountUID
        withOptions:( AcquireIOConfig * _Nullable )optionDictionary;



/**
 * Start a connection session with acquire server. After calling startSession, the AcquireIODelegate delegate will receive either didChangeConnectionStatus: or onError:.
 *
 * **setAccount: should be called first.**
 *
 * @Available Available in SDK version 1.0.9 or later
 */

-(void)startSession;

/** Update configuration after init method calles.
 *  Set an visitor identifier for your visitor.
 *
 * This is part of additional visitor configuration. The user identifier will be passed through to the admin dashboard as "User ID" under customer info.
 *  @param visitorIdentifier A string to identify your visitor.
 *
 *  @available Available in SDK version 1.0.0 or later
 */

- (void) setVisitorIdentifier:(NSString * __nonnull)visitorIdentifier;

/** Set the name, phone and email of the app visitor.
 *
 * This is part of additional visitor configuration. If this is provided through the api, user will not be prompted to re-enter this information again.
 * Pass nil values for both name and email to clear out old existing values.
 *
 *   @param name The name of the user.
 *   @param phone The phone of the user.
 *   @param email The email address of the user.
 *
 *   @available Available in SDK version 1.0.0 or later
 */

- (void) setVisitor:(NSString *_Nullable)name phone:(NSString *_Nullable)phone andEmail:(NSString *_Nullable)email;

/** Set the extra detail of the app visitor.
 *
 * This is part of additional visitor configuration. If this is provided through the api, user will not be prompted to re-enter this information again.
 * Pass nil values for data to clear out old existing values.
 *
 *   @param fields array of field. field dictionary format: {"l":"FIELD_LABEL","n":"FIELD_KEY","v":"FIELD_VALUE"}.
 *
 *   @available Available in SDK version 1.0.11 or later
 */
- (void) setVisitorExtraField:(NSArray *__nonnull)fields;


/**
 If your visitor is identified (i.e., visitor has already logged in your app and you have a email address of visitor), call the following method  before setAccount: an identified user.
 
 @note This must be called before setAccount: takes place and must pass same email in setVisitor:.
 @param visitorHash A HMAC digest of the visitor email.
 *  @available Available in SDK version 1.0.8 or later
 */
- (void)setVisitorHash:(NSString *_Nonnull)visitorHash;

/**
 AcquireIO session connection status
 @return AcquireIOConnectionStatus Enum value.
 *  @available Available in SDK version 1.0.9 or later
 */

- (AcquireIOConnectionStatus) getConnectionStatus;



/**
 If you have set visitor hash (HMAC digest) and visitor just logged out from account and need to manage user integrity with agent, call method logoutVisitor to remove all acquire data from app related to visitorHash.
 
 @note This should be called when visit logged out.
 *  @available Available in SDK version 1.0.8 or later
 */
- (void)logoutVisitor;

/** Show support view controller from current viewcontroller.
 *
 * Pass nil argument will not work.
 *
 *   @param viewController The instance of the UIViewController.
 *   @param reference the reference id for specific thread.
 *
 *   @available Available in SDK version 2.0.10 or later
 */

- (void) showSupport:(UIViewController * __nonnull)viewController withReference:(NSString *_Nonnull)reference;

/**
 show specific thread with reference, and send message

 @param viewController from which viewcontroller you wanna show support view
 @param reference meta field for each thread. should be uniqe by thread
 @param message send a automated message.
 @available Available in SDK version 2.0.12 or later
 
 */
- (void) showSupport:(UIViewController * __nonnull)viewController withReference:(NSString *_Nonnull)reference withMessage:(NSString *_Nonnull)message;
/** Show support view controller from current viewcontroller.
 *
 * Pass nil argument will not work.
 *
 *   @param viewController The instance of the UIViewController.
 *
 *   @available Available in SDK version 1.0.0 or later
 */

- (void) showSupport:(UIViewController * __nonnull)viewController;

/** Show call support view with type.
 *
 * Pass nil argument will not work.
 *
 *   @param callType Type of call (audio/video).
 *
 *   @available Available in SDK version 1.0.0 or later
 */

- (void) showCallSupport:(NSString * __nonnull)callType;



/**
 * Total unread count of message(s).
 *
 * @available Available in SDK version 1.0.0 or later
 */

- (NSInteger) getUnreadCount;

/**
 * Total unread count of message(s).
 *
 * @available Available in SDK version 1.0.0 or later
 */

- (NSInteger) getAvailableAgentCount;

/** Change the SDK language. By default, the device's prefered language is used.
 *  If a AcquireIO session is already active at the time of invocation,
 *  this call will fail and will return false.
 *
 * @param optionDictionary is a dict for additional configuration detail.
 *
 * @available Available in SDK version 1.0.0 or later
 */

- (void) updateOptionDictionary:(AcquireIOConfig * __nonnull)optionDictionary;

/**
 *  Set APNS token for the application. This APNS token will be used to register
 *
 *  @param apnsToken The APNS token for the application.
 *  @param type  The type of APNS token. Debug builds should use
 *  AcquireIOAPNSTokenTypeSandbox. Alternatively, you can supply
 *  AcquireIOAPNSTokenTypeProd to have the type automatically
 *  detected based on your provisioning profile.
 *
 *  @available Available in SDK version 1.0.0 or later
 */
- (void)setAPNSToken:(NSData * __nonnull)apnsToken
                type:(AcquireIOAPNSTokenType)type;

/**
 *  Use this to track message delivery and analytics for messages, typically
 *  when you receive a notification in `application:didReceiveRemoteNotification:`.
 *
 *  @param message The downstream message received by the application.
 *
 *  @return Information about the downstream message.
 *
 *  @available Available in SDK version 1.0.0 or later
 */
- (AcquireIOPushMessageStatus)appDidReceiveMessage:(NSDictionary * __nonnull)message;

/**
 * Set visitor cobrowse code before setAcccount: withOptions: (when auto session start) or startSession (when auto session start off).
 *
 *  @param custom_code Any random integer
 * @available Available in SDK version 1.0.9 or later
 */

- (void) setCobrowseCode:(NSInteger)custom_code;

/**
 * Get visitor cobrowse code, when acquire session ready to connect
 *
 * @available Available in SDK version 1.0.9 or later
 */

- (NSInteger) getCobrowseCode;

/**
 * Start a cobrowse session with a agent.  Note that for Visitor sessions already start sharing when agent start cobrowse session via code. You can Pause and start sharing again.
 *
 * **init: no need to call first time. After pause then you can call this method**
 *
 * @available Available in SDK version 1.0.9 or later
 */

-(void)startSharing;

/**
 * Pause an active cobrowse session
 *
 * @available Available in SDK version 1.0.9 or later
 */

-(void)pauseSharing;

/**
 * End the cobrowse session.  Calling endSharing initiates the process of ending the session.
 *
 * @available Available in SDK version 1.0.9 or later
 */

-(void)endSharing:(BOOL)showPrompt;

/**
 * Adds a UIView to mask during the cobrowse session.
 *
 * @param view  UIView instance to mask _required_
 */
- (void)addMaskedView:(UIView * __nonnull)view;

/**
 * Remove a UIView from being masked during a cobrowse session.
 *
 * @param view  UIView instance to mask _required_
 *
 * @available Available in SDK version 1.0.9 or later
 */
- (void)removeMaskedView:(UIView * __nonnull)view;

/**
 * Masks the keyboard from being shown
 *
 * @param maskKeyboard YES or NO to mask keyboard
 *
 * @available Available in SDK version 1.0.9 or later
 */
- (void)maskKeyboard:(BOOL)maskKeyboard;

/**
 * Upload file direct to acquire server, support file max size: 30MB and format obj, stl, zcode, zproj, png, doc, docx, xls, xlsx, csv, pdf, jpg, jpeg, bmp, zip, psd, ai, gif, rar, 7z
 *
 * @param filePath path/to/local/file
 * @param progress callback block type of AIOUploadProgressBlock will track progres of file uploading
 * @param completion callback type AIOUploadCompletionBlock will call when finish file uploading.
 *
 * @available Available in SDK version 1.0.12 or later
 */

- (void)uploadFileToAcquire:(NSString * __nonnull)filePath progress:(AIOUploadProgressBlock __nonnull)progress completion:(AIOUploadCompletionBlock __nonnull)completion;

@end


/** Protocol declaration AcquireIODelegate
 *
 *  @available Available in SDK version 1.0.0 or later
 */

@protocol AcquireIODelegate <NSObject>

@optional

/** Optional method changeConnectionStatus
 *  @param status ConnectionStatus
 *
 *  @available Available in SDK version 1.0.1 or later
 */

- (void) didChangeConnectionStatus:(AcquireIOConnectionStatus)status;

/** Optional method changeAgentStatus
 *  @param agentID Agent Unique ID
 *  @param status AgentStatus
 *
 *  @available Available in SDK version 1.0.0 or later
 */

- (void) didChangeAgentStatus:(NSString * __nonnull)agentID
                 andStatus:(AcquireIOAgentStatus)status;

/** Optional method updateUnreadStatus. Get total count of unread when receive message from agent and not callback when support view will open
 *  @param unreadTotal Returns the number of unread messages.
 *
 *  @available Available in SDK version 1.0.0 or later
 */

- (void) didUpdateUnreadCount:(NSInteger)unreadTotal;

/** Optional method hideSupport. Call when support view controller hide
 *
 *  @available Available in SDK version 1.0.0 or later
 */

- (void) hideSupport;

/** Optional method trigger event. Create trigger in agent panel on fire rule matched.
 *  @param eventName Returns the name of event string.
 *
 *  @available Available in SDK version 1.0.7 or later
 */

- (void) didReceiveTriggerEvent:(NSString *__nonnull)eventName;

/** Optional method didChangeCobrowseCode. Call when cobrowsing session code changed
 *  @param session_code Cobrowse session code
 *
 *  @available Available in SDK version 1.0.9 or later
 */
-(void) didChangeCobrowseCode:(NSInteger)session_code;


/** Optional method cobrowsingStatusUpdate. Call when cobrowsing screen share connection state change
 *
 *  @available Available in SDK version 1.0.9 or later
 */
-(void) didCobrowseSessionStateChange:(CobrowseSessionStatus)status;


/* App initiates the co-browse session and failed due to decline by the visitor.
 *
 *  @available Available in SDK version 1.0.9 or later
 */

-(void) onCobrowseSessionRequestDecline;


/* When co-browse session request accepted by the visitor
 *
 *  @available Available in SDK version 1.0.9 or later
 */

-(void) onCobrowseSessionRequestSucceeded;

/* When Agent joins the session after entering cobrowse code that is generated in the App. After this callback Agent can see Screen and Session state move from ‘Waiting’ to ‘Connected’
 *
 *  @available Available in SDK version 1.0.9 or later
 */

-(void) onAgentConnected;

/* When Agent Ends the session. Session state move from ‘Active to ‘InActive’
 *
 *  @available Available in SDK version 1.0.9 or later
 */

-(void) onAgentEnded;


/* When session connection failed
 *
 *  @available Available in SDK version 1.0.9 or later
 */
-(void)  onSessionFailed;


/* Any error when socket server connection failed any reason, ie. invalid input data, expire data etc.
 *
 *  @available Available in SDK version 1.0.9 or later
 */
-(void) onError:(NSError * __nonnull)error;


/* When chat tag did change by agent
 *
 *  @available Available in SDK version 1.0.9 or later
 */
-(void)  onTagChange:(NSArray * _Nullable)list;

/* When change status of call support
 *
 *  @available Available in SDK version 1.0.9 or later
 */
-(void)  onCallSupportStatusChange:(AcquireIOCallSupportStatus)status withMessage:(NSString * _Nullable)message;


/**
when user interacts with events

@param type AcquireIOInteractionEventType
@param data NSDictionary
@available Available in SDK version 2.0.14 or later
*/
-(void) didUserInteractedWithEvent:(AcquireIOInteractionEventType) type withData:(NSDictionary *_Nullable)data;


/**
 when user interacts with Callerview

 @param type AcquireIOInteractionEventType
 @available Available in SDK version 2.0.6 or later
 */
-(void) didUserInteractedWithEvent:(AcquireIOInteractionEventType) type  __deprecated_msg("Use didUserInteractedWithEvent: withData: method instead.");

@end
