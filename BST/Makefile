# Makefile

# 定义编译器和编译选项
CXX := g++
CXXFLAGS := -Wall -std=c++11

# 定义LaTeX编译器
LATEX_COMPILER := pdflatex

# 定义目标文件
TARGET := main
REPORT := report

# 默认目标
all: run

# 编译并运行程序
run: $(TARGET)
	./$(TARGET)

# 编译main.cpp生成可执行文件
$(TARGET): main.cpp BinarySearchTree.h
	$(CXX) $(CXXFLAGS) -o $@ main.cpp

# 编译LaTeX文档生成PDF
report: $(REPORT).tex
	$(LATEX_COMPILER) $(REPORT).tex
	$(LATEX_COMPILER) $(REPORT).tex

# 清理编译生成的文件
clean:
	rm -f $(TARGET) *.aux *.log *.out *.pdf

.PHONY: all run report clean