/*===============================================================================
Copyright (c) 2016 PTC Inc. All Rights Reserved.

Copyright (c) 2012-2015 Qualcomm Connected Experiences, Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other 
countries.
===============================================================================*/

#import <UIKit/UIKit.h>

#import <Vuforia/UIGLViewProtocol.h>

#import "Texture.h"
#import "SampleApplicationSession.h"
#import "SampleApplication3DModel.h"
#import "SampleGLResourceHandler.h"
#import "SampleAppRenderer.h"

#define kNumAugmentationTextures 4


// EAGLView is a subclass of UIView and conforms to the informal protocol UIGLViewProtocol
// EAGLView是UIView的子类，符合非正式协议UIGLViewProtocol
@interface ImageTargetsEAGLView : UIView <UIGLViewProtocol, SampleGLResourceHandler, SampleAppRendererControl> {
@private
    // OpenGL ES context  OpenGL ES 上下文
    EAGLContext *context;
    
    // The OpenGL ES names for the framebuffer and renderbuffers used to render to this view
    // 用于渲染到此视图的framebuffer和renderbuffers的OpenGL ES名称
    GLuint defaultFramebuffer; // 默认帧缓冲区
    GLuint colorRenderbuffer; // 颜色渲染
    GLuint depthRenderbuffer; // 深度渲染

    // Shader handles
    // 着色器处理
    GLuint shaderProgramID; // 着色器程序id
    GLint vertexHandle; // 顶点处理
    GLint normalHandle; // 通常处理
    GLint textureCoordHandle; // 质地坐标处理
    GLint mvpMatrixHandle; // 矩阵处理
    GLint texSampler2DHandle; // 2D取样处理
    
    // Texture used when rendering augmentation
    // 绘制渲染时使用的纹理
    Texture* augmentationTexture[kNumAugmentationTextures];
    
    BOOL offTargetTrackingEnabled;
    SampleApplication3DModel * buildingModel; // 建筑模型
    
    SampleAppRenderer * sampleAppRenderer; // 渲染图层
}

@property (nonatomic, weak) SampleApplicationSession * vapp;

- (id)initWithFrame:(CGRect)frame appSession:(SampleApplicationSession *) app;

- (void)finishOpenGLESCommands;
- (void)freeOpenGLESResources;

- (void) setOffTargetTrackingMode:(BOOL) enabled;
- (void)configureVideoBackgroundWithViewWidth:(float)viewWidth andHeight:(float)viewHeight;
- (void) updateRenderingPrimitives;
@end
