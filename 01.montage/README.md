> 本项目制作montage效果，data为源图片的路径

业务逻辑：
1. 读取图片（目标效果图片，资源库图片） 
2. 分析目标效果图片，从资源库图片当中找到匹配的图片 
3. 进行图片组合 
4. 生成结果图片

工程逻辑：
1. 创建工程项目 
   1. 创建工程文件夹Montage 
   2. 将相关资源导入到项目中 
   3. 使用CMake进行编写
2. 创建对应的代码源文件 
   1. 创建CMakeLists.txt 
   2. 创建montage.cpp 
   3. 创建工作目录build
3. 按照业务逻辑制作相关代码
4. 验证效果