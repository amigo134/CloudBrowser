# CloudBrowser

云存储浏览器 - 基于Qt开发的云对象存储浏览器应用

## 作者信息

**作者**: amigo134bbbb





## 项目简介

CloudBrowser 是一个基于 Qt 5.15.2 开发的云对象存储浏览器应用，支持腾讯云对象存储（COS）服务。

## 主要功能

- 用户登录认证
- 存储桶（Bucket）管理
  - 查看存储桶列表
  - 创建存储桶
  - 删除存储桶
- 对象（Object）管理
  - 浏览对象列表
  - 上传文件
  - 下载文件
- 文件传输进度显示

## 技术栈

- **开发框架**: Qt 5.15.2
- **编译器**: MSVC 2019
- **云存储SDK**: 腾讯云COS SDK
- **依赖库**: 
  - Poco C++ Libraries
  - RapidXML

## 项目结构

```
CloudBrowser/
├── qosbrowser/          # 主程序源代码
│   ├── src/
│   │   ├── bend/        # 后端逻辑层
│   │   ├── fend/        # 前端界面层
│   │   ├── config/      # 配置文件
│   │   ├── helper/      # 辅助工具类
│   │   ├── middle/      # 中间层（模型和信号）
│   │   └── plugins/     # 插件管理
│   └── static/          # 静态资源文件
├── test/                # 测试代码
├── third/               # 第三方库
└── build/               # 编译输出目录
```

## 构建说明

本项目使用 Qt Creator 和 qmake 进行构建。

### 环境要求

- Qt 5.15.2 或更高版本
- MSVC 2019 编译器
- Windows 10 或更高版本

### 编译步骤

1. 使用 Qt Creator 打开 `CloudBrowser.pro` 文件
2. 配置编译套件（MSVC 2019 64位）
3. 构建项目

## 许可证

请参考第三方库的许可证信息：
- 腾讯云 COS SDK: Copyright (c) 2017, Tencent Inc.
- Poco C++ Libraries: Applied Informatics Software Engineering GmbH
- RapidXML: Marcin Kalicinski

## 联系方式

作者: amigo134

