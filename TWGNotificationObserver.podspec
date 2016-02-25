Pod::Spec.new do |s|
  s.name             = "TWGNotificationObserver"
  s.version          = "0.1.1"
  s.summary          = "Helper for working with NSNotificationCenter"

  s.description      = <<-DESC
                        Helper for working with NSNotificationCenter. Makes it easier to fire blocks in response to notifications.
                       DESC

  s.homepage         = "https://github.com/twg/TWGNotificationObserver"
  s.license          = 'MIT'
  s.author           = { "The Working Group": "mobile@twg.ca" }
  s.source           = { :git => "https://github.com/twg/TWGNotificationObserver.git", :tag => s.version.to_s }

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'Pod/Classes/**/*'
  s.resource_bundles = {
    'TWGNotificationObserver' => ['Pod/Assets/*.png']
  }

end
