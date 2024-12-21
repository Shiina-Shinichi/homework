# 编译器和编译选项
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# 可执行文件名
TARGET = expression_evaluator

# 源文件
SRCS = main.cpp

# 目标文件
OBJS = $(SRCS:.cpp=.o)

# LaTeX 文件
LATEX = xelatex
TEX_FILE = report.tex

# 默认目标：编译和链接
all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# 编译 main.cpp 为 main.o
main.o: main.cpp expression_evaluator.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# 编译 LaTeX 文件报告
report: $(TEX_FILE)
	$(LATEX) $(TEX_FILE)
	$(LATEX) $(TEX_FILE)  # 运行两次 LaTeX 来生成正确的引用等

# 清理目标文件和可执行文件
clean:
	rm -f $(OBJS) $(TARGET) report.pdf

# 清理 LaTeX 生成的辅助文件
clean_latex:
	rm -f *.aux *.log *.out *.toc *.lof *.lot

# 伪目标，用于避免与文件同名的冲突
.PHONY: all clean clean_latex report

# 运行程序
run: $(TARGET)
	./$(TARGET)
