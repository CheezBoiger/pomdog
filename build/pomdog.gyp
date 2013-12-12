{
  'includes': ['common.gypi'],
  'make_global_settings': [
    ['CXX','/usr/bin/clang++'],
    ['LINK','/usr/bin/clang++'],
  ],
  'conditions': [
    ['OS == "win"', {
      'variables': {
        'renderer%': 'd3d11',
        #'input_device%': 'dinput8',
      },
    }],
    ['OS == "mac"', {
      'variables': {
        'renderer%': 'opengl',
		#'input_device%': 'none',
      },
    }],
    ['OS == "linux" or OS == "freebsd" or OS == "openbsd"', {
      'variables': {
        'renderer%': 'opengl',
		#'input_device%': 'none',
      },
    }],
  ],
  'target_defaults': {
    #'dependencies': [
    #],
    'include_dirs': [
      '../include',
      '../third_party/boost/include',
    ],
    'msvs_settings':{
      'VCCLCompilerTool': {
        'WarningLevel': '4',   # /W4
        'WarnAsError': 'true', # /WX
      },
    },
    'xcode_settings': {
      'GCC_VERSION': 'com.apple.compilers.llvm.clang.1_0',
      'CLANG_CXX_LANGUAGE_STANDARD': 'c++0x',
      'MACOSX_DEPLOYMENT_TARGET': '10.8', # OS X Deployment Target: 10.8
      'CLANG_CXX_LIBRARY': 'libc++', # libc++ requires OS X 10.7 or later
      # Warnings:
      'GCC_WARN_64_TO_32_BIT_CONVERSION': 'YES',
      'GCC_WARN_ABOUT_DEPRECATED_FUNCTIONS': 'YES',
      'GCC_WARN_ABOUT_MISSING_NEWLINE': 'YES',
      'GCC_WARN_ABOUT_RETURN_TYPE': 'YES',
      'GCC_WARN_CHECK_SWITCH_STATEMENTS': 'YES',
      'GCC_WARN_HIDDEN_VIRTUAL_FUNCTIONS': 'YES',
      #'GCC_WARN_INITIALIZER_NOT_FULLY_BRACKETED': 'YES',
      'GCC_WARN_NON_VIRTUAL_DESTRUCTOR': 'YES',
      #'GCC_WARN_SHADOW': 'YES',
      'GCC_WARN_SIGN_COMPARE': 'YES',
      'GCC_WARN_TYPECHECK_CALLS_TO_PRINTF': 'YES',
      'GCC_WARN_UNUSED_FUNCTION': 'YES',
      'GCC_WARN_UNUSED_LABEL': 'YES',
      'GCC_WARN_UNUSED_VALUE': 'YES',
      'GCC_WARN_UNUSED_VARIABLE': 'YES',
      'GCC_TREAT_WARNINGS_AS_ERRORS': 'YES',
      'WARNING_CFLAGS': [
        '-Wall',
      ],
      # Symbols:
      'CLANG_ENABLE_OBJC_ARC': 'YES',
      'GCC_INLINES_ARE_PRIVATE_EXTERN': 'YES', # '-fvisibility-inlines-hidden'
      'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES', # '-fvisibility=hidden'
    },
  },
  'variables': {
    'pomdog_library_testable_sources': [
      '../include/Pomdog/Config/Export.hpp',
      '../include/Pomdog/Config/FundamentalTypes.hpp',
      '../include/Pomdog/Config/Platform.hpp',
      '../include/Pomdog/Event/Event.hpp',
      '../include/Pomdog/Event/EventCode.hpp',
      '../include/Pomdog/Event/EventCodeHelper.hpp',
      '../include/Pomdog/Event/EventConnection.hpp',
      '../include/Pomdog/Event/EventHandler.hpp',
      '../include/Pomdog/Event/EventQueue.hpp',
      '../include/Pomdog/Event/ScopedConnection.hpp',
      '../include/Pomdog/Event/detail/EventArguments.hpp',
      '../include/Pomdog/Event/detail/FowardDeclarations.hpp',
      '../include/Pomdog/GamePlay/GameObject.hpp',
      '../include/Pomdog/GamePlay/detail/GameComponent.hpp',
      '../include/Pomdog/Logging/Log.hpp',
      '../include/Pomdog/Logging/LogChannel.hpp',
      '../include/Pomdog/Logging/LogEntry.hpp',
      '../include/Pomdog/Logging/LoggingLevel.hpp',
      '../include/Pomdog/Logging/LogStream.hpp',
      '../include/Pomdog/Math/Color.hpp',
      '../include/Pomdog/Math/ContainmentType.hpp',
      '../include/Pomdog/Math/Degree.hpp',
      '../include/Pomdog/Math/MathHelper.hpp',
      '../include/Pomdog/Math/Matrix2x2.hpp',
      '../include/Pomdog/Math/Matrix3x3.hpp',
      '../include/Pomdog/Math/Matrix4x4.hpp',
      '../include/Pomdog/Math/Point2D.hpp',
      '../include/Pomdog/Math/Point3D.hpp',
      '../include/Pomdog/Math/Quaternion.hpp',
      '../include/Pomdog/Math/Radian.hpp',
      '../include/Pomdog/Math/Rectangle.hpp',
      '../include/Pomdog/Math/Vector2.hpp',
      '../include/Pomdog/Math/Vector3.hpp',
      '../include/Pomdog/Math/Vector4.hpp',
      '../include/Pomdog/Math/detail/Coordinate2D.hpp',
      '../include/Pomdog/Math/detail/Coordinate2DImplementation.hpp',
      '../include/Pomdog/Math/detail/Coordinate3D.hpp',
      '../include/Pomdog/Math/detail/Coordinate3DImplementation.hpp',
      '../include/Pomdog/Math/detail/FloatingPointColor.hpp',
      '../include/Pomdog/Math/detail/FloatingPointMatrix2x2.hpp',
      '../include/Pomdog/Math/detail/FloatingPointMatrix3x3.hpp',
      '../include/Pomdog/Math/detail/FloatingPointMatrix4x4.hpp',
      '../include/Pomdog/Math/detail/FloatingPointQuaternion.hpp',
      '../include/Pomdog/Math/detail/FloatingPointVector2.hpp',
      '../include/Pomdog/Math/detail/FloatingPointVector3.hpp',
      '../include/Pomdog/Math/detail/FloatingPointVector4.hpp',
      '../include/Pomdog/Math/detail/ForwardDeclarations.hpp',
      '../include/Pomdog/Math/detail/TaggedArithmetic.hpp',
      '../include/Pomdog/Utility/Assert.hpp',
      '../include/Pomdog/Utility/Exception.hpp',
      '../include/Pomdog/Utility/Noncopyable.hpp',
      '../include/Pomdog/Utility/detail/Tagged.hpp',
      '../src/Event/Event.cpp',
      '../src/Event/EventCodeHelper.cpp',
      '../src/Event/EventConnection.cpp',
      '../src/Event/EventHandler.cpp',
      '../src/Event/EventQueue.cpp',
      '../src/Event/ScopedConnection.cpp',
      '../src/Event/detail/EventSlot.cpp',
      '../src/Event/detail/EventSlot.hpp',
      '../src/Event/detail/EventSlotCollection.cpp',
      '../src/Event/detail/EventSlotCollection.hpp',
      '../src/GamePlay/GameObject.cpp',
      '../src/Logging/Log.cpp',
      '../src/Logging/LogChannel.cpp',
      '../src/Logging/LogStream.cpp',
      '../src/Math/MathHelper.cpp',
      '../src/Math/Rectangle.cpp',
      '../src/Math/detail/FloatingPointColor.cpp',
      '../src/Math/detail/FloatingPointMatrix2x2.cpp',
      '../src/Math/detail/FloatingPointMatrix3x3.cpp',
      '../src/Math/detail/FloatingPointMatrix4x4.cpp',
      '../src/Math/detail/FloatingPointQuaternion.cpp',
      '../src/Math/detail/FloatingPointVector2.cpp',
      '../src/Math/detail/FloatingPointVector3.cpp',
      '../src/Math/detail/FloatingPointVector4.cpp',
      '../src/Utility/CRC32.cpp',
      '../src/Utility/CRC32.hpp',
      '../src/Utility/HashingHelper.hpp',
      '../src/Utility/ScopeGuard.hpp',
    ],
    'pomdog_library_application_sources': [
      '../include/Pomdog/Application/Game.hpp',
      '../include/Pomdog/Application/GameHost.hpp',
      '../include/Pomdog/Application/GameWindow.hpp',
      '../include/Pomdog/Application/detail/PlatformSystem.hpp',
      '../include/Pomdog/Graphics/Blend.hpp',
      '../include/Pomdog/Graphics/BlendDescription.hpp',
      '../include/Pomdog/Graphics/BlendFunction.hpp',
      '../include/Pomdog/Graphics/BlendState.hpp',
      '../include/Pomdog/Graphics/BufferUsage.hpp',
      '../include/Pomdog/Graphics/ClearOptions.hpp',
      '../include/Pomdog/Graphics/ComparisonFunction.hpp',
      '../include/Pomdog/Graphics/CullMode.hpp',
      '../include/Pomdog/Graphics/DepthStencilDescription.hpp',
      '../include/Pomdog/Graphics/DepthStencilOperation.hpp',
      '../include/Pomdog/Graphics/DepthStencilState.hpp',
      '../include/Pomdog/Graphics/FillMode.hpp',
      '../include/Pomdog/Graphics/GraphicsContext.hpp',
      '../include/Pomdog/Graphics/GraphicsDevice.hpp',
      '../include/Pomdog/Graphics/RasterizerDescription.hpp',
      '../include/Pomdog/Graphics/RasterizerState.hpp',
      '../include/Pomdog/Graphics/SamplerDescription.hpp',
      '../include/Pomdog/Graphics/SamplerState.hpp',
      '../include/Pomdog/Graphics/StencilOperation.hpp',
      '../include/Pomdog/Graphics/TextureAddressMode.hpp',
      '../include/Pomdog/Graphics/TextureFilter.hpp',
      '../include/Pomdog/Graphics/Viewport.hpp',
      '../include/Pomdog/Graphics/detail/ForwardDeclarations.hpp',
      '../include/Pomdog/Input/ButtonState.hpp',
      '../include/Pomdog/Input/Mouse.hpp',
      '../include/Pomdog/Input/MouseState.hpp',
      '../src/Application/SystemEventDispatcher.hpp',
      '../src/Graphics/BlendDescription.cpp',
      '../src/Graphics/BlendState.cpp',
      '../src/Graphics/ClearOptions.cpp',
      '../src/Graphics/DepthStencilDescription.cpp',
      '../src/Graphics/DepthStencilState.cpp',
      '../src/Graphics/GraphicsContext.cpp',
      '../src/Graphics/GraphicsDevice.cpp',
      '../src/Graphics/RasterizerState.cpp',
      '../src/Graphics/SamplerState.cpp',
      '../src/Graphics/Viewport.cpp',
      '../src/Input/MouseState.cpp',
      '../src/RenderSystem/NativeBlendState.hpp',
      '../src/RenderSystem/NativeDepthStencilState.hpp',
      '../src/RenderSystem/NativeGraphicsContext.hpp',
      '../src/RenderSystem/NativeGraphicsDevice.hpp',
      '../src/RenderSystem/NativeRasterizerState.hpp',
      '../src/RenderSystem/NativeSamplerState.hpp',
    ],
    'pomdog_library_opengl4_sources': [
      '../src/RenderSystem.GL4/BlendStateGL4.cpp',
      '../src/RenderSystem.GL4/BlendStateGL4.hpp',
      '../src/RenderSystem.GL4/DepthStencilStateGL4.cpp',
      '../src/RenderSystem.GL4/DepthStencilStateGL4.hpp',
      '../src/RenderSystem.GL4/ErrorChecker.cpp',
      '../src/RenderSystem.GL4/ErrorChecker.hpp',
      '../src/RenderSystem.GL4/GraphicsContextGL4.cpp',
      '../src/RenderSystem.GL4/GraphicsContextGL4.hpp',
      '../src/RenderSystem.GL4/GraphicsDeviceGL4.cpp',
      '../src/RenderSystem.GL4/GraphicsDeviceGL4.hpp',
      '../src/RenderSystem.GL4/OpenGLContext.hpp',
      '../src/RenderSystem.GL4/OpenGLPrerequisites.hpp',
      '../src/RenderSystem.GL4/RasterizerStateGL4.cpp',
      '../src/RenderSystem.GL4/RasterizerStateGL4.hpp',
      '../src/RenderSystem.GL4/SamplerStateGL4.cpp',
      '../src/RenderSystem.GL4/SamplerStateGL4.hpp',
    ],
    'pomdog_library_cocoa_sources': [
      '../include/Pomdog/Application/detail/Platform.Cocoa/BootstrapperCocoa.hpp',
      '../src/Platform.Cocoa/BootstrapperCocoa.mm',
      '../src/Platform.Cocoa/CocoaGameHost.hpp',
      '../src/Platform.Cocoa/CocoaGameHost.mm',
      '../src/Platform.Cocoa/CocoaGameWindow.hpp',
      '../src/Platform.Cocoa/CocoaGameWindow.mm',
      '../src/Platform.Cocoa/CocoaMouse.hpp',
      '../src/Platform.Cocoa/CocoaMouse.cpp',
      '../src/Platform.Cocoa/CocoaOpenGLContext.hpp',
      '../src/Platform.Cocoa/CocoaOpenGLContext.mm',
      '../src/Platform.Cocoa/CocoaOpenGLView.hpp',
      '../src/Platform.Cocoa/CocoaOpenGLView.mm',
      '../src/Platform.Cocoa/CocoaOpenGLViewDelegate.hpp',
      '../src/Platform.Cocoa/CocoaOpenGLViewDelegate.mm',
      '../src/Platform.Cocoa/CocoaWindowDelegate.hpp',
      '../src/Platform.Cocoa/CocoaWindowDelegate.mm',
      '../src/Platform.Cocoa/PlatformSystemCocoa.cpp',
    ],
  },
  'targets': [
    {
      'target_name': 'pomdog-testable',
      'product_name': 'pomdog-testable',
      'type': 'static_library',
      'defines': ['POMDOG_USING_LIBRARY_EXPORTS=1'],
      'dependencies': [
      ],
      'include_dirs': [
        '../include',
      ],
      'sources': [
        '<@(pomdog_library_testable_sources)',
      ],
    },
    {
      'target_name': 'pomdog-static',
      'product_name': 'pomdog', # libpomdog.a or libpomdog.lib
      'type': 'static_library',
      'defines': ['POMDOG_USING_LIBRARY_EXPORTS=1'],
      'dependencies': [
      ],
      'include_dirs': [
        '../include',
      ],
      'sources': [
        '<@(pomdog_library_testable_sources)',
        '<@(pomdog_library_application_sources)',
        '../include/Pomdog/Pomdog.hpp',
      ],
      'conditions': [
        ['renderer == "d3d11"', {
          'sources': [
          ],
          'link_settings': {
            'libraries': [
              '-ldxgi.lib',
              '-ld3d11.lib',
              '-ld3dcompiler.lib',
            ],
          },
        }],
        ['renderer == "opengl"', {
          'sources': [
            '<@(pomdog_library_opengl4_sources)',
          ],
        }],
        ['OS == "mac" and renderer == "opengl"', {
          'sources': [
            '<@(pomdog_library_cocoa_sources)',
          ],
          'link_settings': {
            'libraries': [
              '$(SDKROOT)/System/Library/Frameworks/Cocoa.framework',
              '$(SDKROOT)/System/Library/Frameworks/OpenGL.framework',
            ],
          },
        }], # OS == "mac"
      ],
    },
    {
      'target_name': 'pomdog-shared',
      'product_name': 'Pomdog',
      'type': 'shared_library',
      'defines': ['POMDOG_BUILDING_LIBRARY_EXPORTS=1'],
      'mac_bundle': 1,
      'dependencies': [
      ],
      'include_dirs': [
        '../include',
      ],
      'sources': [
        '<@(pomdog_library_testable_sources)',
        '<@(pomdog_library_application_sources)',
        '../include/Pomdog/Pomdog.hpp',
      ],
      'conditions': [
        ['renderer == "d3d11"', {
          'sources': [
          ],
          'link_settings': {
            'libraries': [
              '-ldxgi.lib',
              '-ld3d11.lib',
              '-ld3dcompiler.lib',
            ],
          },
        }],
        ['renderer == "opengl"', {
          'sources': [
            '<@(pomdog_library_opengl4_sources)',
          ],
        }],
        ['OS == "mac" and renderer == "opengl"', {
          'sources': [
            '<@(pomdog_library_cocoa_sources)',
          ],
          'link_settings': {
            'libraries': [
              '$(SDKROOT)/System/Library/Frameworks/Cocoa.framework',
              '$(SDKROOT)/System/Library/Frameworks/OpenGL.framework',
            ],
          },
        }], # OS == "mac"
      ],
      'xcode_settings': {
        'INFOPLIST_FILE': '../src/Platform.Cocoa/Xcode/Pomdog-Info.plist',
        'DYLIB_INSTALL_NAME_BASE': '@executable_path/../../..',
      },
    },
  ],# "targets"
}
