# UCL_Interface（UCL包展示） #
  

## 1. 使用方式##
1. 输入UCL包的路径，点击“打开”按钮。
2. 点击UCL Code区域的按钮，弹出消息框，显示该Code域的值。
3. 点击UCL Properties区域的按钮，弹出主头部的信息展示窗口或对应属性集合的窗口。
4. 在属性集合窗口，点击相应按钮显示该属性元素的信息。
5. 在“属性元素信息”点击“详细”按钮，窗口展开，显示属性元素的详细信息。

## 2.待解决问题 ##
1. UCL Code属性部分的展示未完成。
2. 转移至Qt。
3. 更新项目文件。
  
## 3.Tips ##
1. 设置按钮是否可用。

    GetDlgItem(IDC_BUTTON_Provenance)->EnableWindow(FALSE);

2. 窗口类中增加public变量，根据不同的按钮传递不同变量值从而使窗口展示不同的信息。

3. 窗口的展开和收起可以使用picture control绘制一条直线，加入如下代码：
	
	//smallRect 和 largeRect都是窗口类的public变量
	smallRect = new CRect;
	largeRect = new CRect;
	CRect rectSeparator;
	GetWindowRect(largeRect);
	GetDlgItem(IDC_STATIC_Seperator)->GetWindowRect(&rectSeparator);
	
	smallRect->left = largeRect->left;
	smallRect->right = largeRect->right;
	smallRect->top = largeRect->top;
	smallRect->bottom = rectSeparator.bottom;

	SetWindowPos(NULL, 0, 0, smallRect->Width(), smallRect->Height(),SWP_NOMOVE);//设置窗口位置


**新建ReadMe.md。添加使用方式、待解决问题、Tips[1~3]。**  
**2017.7.1**
