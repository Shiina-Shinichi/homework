# 定义编译器和链接器
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# 定义 LaTeX 编译器
PDFLATEX = pdflatex

# 定义目标文件
TARGET = test
REPORT_PDF = report.pdf

# 默认目标
all: $(TARGET) $(REPORT_PDF)

# 编译 C++ 程序
$(TARGET): test.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# 编译 LaTeX 文档
$(REPORT_PDF): report.tex
	$(PDFLATEX) $<
	$(PDFLATEX) $<

# 清理生成的文件
clean:
	rm -f $(TARGET) $(REPORT_PDF) *.aux *.log *.out *.toc *~

# 防止 make 根据文件名自动推导规则
.PHONY: all clean