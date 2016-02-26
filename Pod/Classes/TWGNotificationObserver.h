#import <Foundation/Foundation.h>

@interface TWGNotificationObserver : NSObject

/**
 *  Returns an NSArray of all notification names passed in via init, useful for unit tests
 */
@property (nonatomic, strong, readonly) NSArray<NSString *> *notificationNames;
/**
 *  Returns the fireBlock passed in via init, useful for unit tests
 */
@property (nonatomic, copy, readonly) void (^fireBlock)();
/**
 *  Returns the NSNotificationCenter used by this object. If you do not pass in a
 *  NSNotificationCenter on init, it will return [NSNotificationCenter defaultCenter]
 */
@property (nonatomic, strong, readonly) NSNotificationCenter *notificationCenter;

/**
 *  Executes a block when we post an NSNotification with a certain name. Since there is no
 *  NSNotificationCenter parameter, [NSNotificationCenter defaultCenter] will be used as the
 *  notification dispatch table
 *
 *  @param notificationName The name of the notification the NSNotificationCenter will observe
 *  @param fireBlock        The block to execute when the NSNotificationCenter receives an
 *                          NSNotification with the given name
 *
 *  @return We will return self
 */
- (instancetype)initWithNotificationName:(NSString *)notificationName
                               fireBlock:(void (^)(NSNotification *notification))fireBlock;

/**
 *  Executes a block when we post an NSNotification with a certain name. Since there is no
 *  NSNotificationCenter parameter, [NSNotificationCenter defaultCenter] will be used as the
 *  notification dispatch table.
 *
 *  @param notificationName The name of the notification the NSNotificationCenter will observe
 *  @param object           The object associated with the notification. Usually this is the
 *                          object that posts the notification
 *  @param fireBlock        The block to execute when the NSNotificationCenter receives an
 *                          NSNotification with the given name
 *
 *  @return We will return self
 */
- (instancetype)initWithNotificationName:(NSString *)notificationName
                                  object:(id)object
                               fireBlock:(void (^)(NSNotification *notification))fireBlock;

/**
 *  Executes a block when we post an NSNotification with a certain names. Since there is no
 *  NSNotificationCenter parameter, [NSNotificationCenter defaultCenter] will be used as the
 *  notification dispatch table.
 *
 *  @param notificationNames An array of name notifications the NSNotificationCenter will observe.
 *                           These objects should be of type NSString
 *  @param fireBlock         The block to execute when the NSNotificationCenter receives an
 *                           NSNotification with the given name
 *
 *  @return We will return self
 */
- (instancetype)initWithNotificationNames:(NSArray<NSString *> *)notificationNames
                                fireBlock:(void (^)(NSNotification *notification))fireBlock;

/**
 *  Executes a block when we post an NSNotification with certain names.
 *
 *  @param notificationNames  An array of NSNotification names the NSNotificationCenter will observe.
 *                            These objects must be of type NSString
 *  @param notificationCenter The NSNotificationCenter object used to broadcast the notifications
 *  @param fireBlock          The block to execute when the NSNotificationCenter receives an
 *                            NSNotification with the given name
 *
 *  @return We will return self
 */
- (instancetype)initWithNotificationNames:(NSArray<NSString *> *)notificationNames
                       notificationCenter:(NSNotificationCenter *)notificationCenter
                                fireBlock:(void (^)(NSNotification *notification))fireBlock;

/**
 *  Executes a block when we post an NSNotification with certain names.
 *
 *  @param notificationNames  An array of NSNotification names the NSNotificationCenter will observe.
 *                            These objects must be of type NSString
 *  @param notificationCenter The NSNotificationCenter object used to broadcast the notifications
 *  @param object             The object associated with the notification. Usually this is the
 *                            object that posts the notification
 *  @param fireBlock          The block to execute when the NSNotificationCenter receives an
 *                            NSNotification with the given name
 *
 *  @return We will return self
 */
- (instancetype)initWithNotificationNames:(NSArray<NSString *> *)notificationNames
                       notificationCenter:(NSNotificationCenter *)notificationCenter
                                   object:(id)object
                                fireBlock:(void (^)(NSNotification *notification))fireBlock;

@end
