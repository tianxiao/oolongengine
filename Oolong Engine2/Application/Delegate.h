//
//  Delegate.h
//
//  Created by Wolfgang Engel on 3/21/08.
//  Copyright __MyCompanyName__ 2008. All rights reserved.
//
#import "GraphicsDevice.h"
#include "Camera.h"


@class UIView;
@class UIGLView;

// CLASS INTERFACES:
@interface UIAppView : UIGLCameraView
{

}


@end

@interface AppController : NSObject
{
	UIWindow*			_window;
	EAGLView*			_glView;
}


@end



