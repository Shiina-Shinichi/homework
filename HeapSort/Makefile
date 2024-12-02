# 设置编译器和编译选项
CXX = g++
CXXFLAGS = -std=c++11 -O2  # 添加了 -O2 优化选项
LDFLAGS = 

# 源代码文件
SRCS = test.cpp HeapSort.h
OBJS = test.o

# 输出文件名
TARGET = test
REPORT = report.tex

# 默认目标
all: $(TARGET)

# 编译 test.cpp 生成目标文件 test.o
test.o: test.cpp HeapSort.h
	$(CXX) $(CXXFLAGS) -c test.cpp  # 使用优化选项编译

# 编译链接生成可执行文件
$(TARGET): test.o
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# 生成报告 (需要安装 pdflatex)
report: $(REPORT)
	pdflatex $(REPORT)

# 清理目标文件和可执行文件
clean:
	rm -f $(OBJS) $(TARGET) *.pdf
