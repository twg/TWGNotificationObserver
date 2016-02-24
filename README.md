# TWGNotificationObserver

## Usage
#### Observing a single notification
```
__weak typeof(self) weakSelf;
self.notificationObserver =
[[TWGNotificationObserver alloc] initWithNotificationName:@"NotificationName"
fireBlock:^(NSNotification *notification) {
[weakSelf someMethod];
}];
[[NSNotificationCenter defaultCenter] postNotificationName:@"NotificationName" object:self];

``` 
#### Observing a multiple notifications
```
__weak typeof(self) weakSelf;
self.notificationObserver =
[[TWGNotificationObserver alloc] initWithNotificationNames:@["Name1", "Name2"] fireBlock:^(NSNotification *notification) {
[weakSelf someMethod];
}];
[[NSNotificationCenter defaultCenter] postNotificationName:@"Name1" object:self];
```


## Benefits
* Abstracts away redundant NSNotificationCenter boilerplate
* Automatically unsubscribes from notifications when deallocated

## Limitations
* Some more functionality with the `userInfo` property on `NSNotification` could be useful in the future
* The controller captures the block, so any reference to `self` inside the block will result in a retain cycle. You must remember to use `weakSelf`.

## Contributing

To run the example project, clone the repo, and run `pod install` from the Example directory first.

Submit updates through a pull request

## Installation

TWGNotificationObserver is available through [CocoaPods](http://cocoapods.org). To install
it, ensure your Podfile sources the TWG specs repo:

```ruby
source "https://github.com/twg/cocoapod-specs.git"
```

Then, simply add the following line to your Podfile:

```ruby
pod "TWGNotificationObserver"
```

## Author

The Working Group, mobile@twg.ca

## License

TWGNotificationObserver is available under the MIT license. See the LICENSE file for more info.
