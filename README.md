# 流量计标定系统上位机

&#160; &#160; &#160; &#160; 流量计标定系统用来标定超声波流量计，使用485串口总线进行通信，协议使用Modbus RTU，界面采用多界面显示。

## 项目特性
### 1. 端口自动搜索
&#160; &#160; &#160; &#160; 本项目由于各物理设备使用的协议有一定差异，故上位机使用多个端口进行通信，但这样用户查找端口就存在不便，分辨不清各个端口和物理设备的对应关系，因此本项目设计自动端口搜索算法来进行端口查找。<br/>
&#160; &#160; &#160; &#160; 开始调用Qt中API函数查找到所有可用的端口，接着轮询各个端口，判断端口是否打开，若已打开则进行下一端口轮询，否则使用协议数据向该端口发送，同时开启定时器，若一定时间内收到响应数据，则该端口为目标设备端口，获取端口号并显示之后，进行下个设备端口的查找；若未收到响应数据则进行下一端口轮询，直到有数据响应，若遍历完所有端口后，均未有响应数据，则提示用户该物理设备可能未与PC机连接。

### 2.绘图工具包QCustomPlot
&#160; &#160; &#160; &#160; 本项目使用第三方开源库QCustomPlot来绘制数据曲线。<br/>
<center>![QCustomPlot](https://github.com/ZhangYiXiSucceed/FlowCalibration/blob/master/IMG/QCustomPlot.jpg)</center><br/>
<center>开源第三方库QCustomPlot</center><br/>
&#160; &#160; &#160; &#160; QCustomPlot是用于绘图和数据可视化的Qt C ++小部件。它没有进一步的依赖关系，并且有据可查。该绘图库专注于制作美观，出版质量的2D绘图，图形和图表，以及为实时可视化应用程序提供高性能。QCustomPlot可以导出为各种格式，例如矢量化的PDF文件和光栅化的图像（如PNG，JPG和BMP）。QCustomPlot是用于在应用程序内部显示实时数据以及为其他媒体生成高质量图的解决方案。
官方网址：https://www.qcustomplot.com/index.php/introduction

### 3.Modbus RTU协议数据解析
&#160; &#160; &#160; &#160; 本项目上位机使用Modbus协议和流量计设备通信。由于上位机没有像单片机那样的中断函数进行接收，所以接收不定长的数据需要一定的逻辑处理。
Qt中串口API函数对接收数据进行封装，可以通过信号与槽来判断接收信号，当信号来了之后，同时开启定时器定时，一定时间后认为数据接收完成，然后执行数据校验解析存储。使用延时等待也可以接收数据，但是主线程中延时会使得界面无响应，如数据持续接收，可能造成溢出使得系统崩溃，而使用定时器则没有这个风险，可以定时处理数据，避免了数据积压带来的问题。

## 软件附图
![FlowCalibration](https://github.com/ZhangYiXiSucceed/FlowCalibration/blob/master/IMG/FlowCalibration.png)
![SetParameter](https://github.com/ZhangYiXiSucceed/FlowCalibration/blob/master/IMG/SetParameter.png)
## 关于本项目
+ 项目作者：ZGQ
+ 邮箱：Guoqingzhang0813@163.com
+ 开发环境：QT51.0,Qt_Creator,MinGW
+ 适用平台：WIndow、Linux

