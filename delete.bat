@echo off
set DIR=%cd%
echo 批量删除指定类型文件
echo &set /p strtemp2="请输入要删除文件类型后缀名:"
setlocal enabledelayedexpansion
for /R %DIR% %%f in (*.%strtemp2%) do (
	echo %%f
	del %%f
)
echo 所有.%strtemp2%删除成功!
pause
