TARGET = qt_lab1
PRO_FILE = qt_lab1.pro
MAKEFILE_QT = Makefile.qt

SRC_DIR = src
BUILD_DIR = build
DOCS_DIR = docs

DOC_SOURCE = $(DOCS_DIR)/index.typ
DOC_OUTPUT = $(BUILD_DIR)/index.pdf

.PHONY: all run docs clean qmake

all: qmake
	@echo "Сборка Qt приложения..."
	@$(MAKE) -f $(MAKEFILE_QT)
	@$(MAKE) docs

qmake: $(PRO_FILE)
	@echo "Генерация Makefile из .pro файла..."
	@qmake $(PRO_FILE) -o $(MAKEFILE_QT)

run: all
	@echo "Запуск приложения..."
	@./$(BUILD_DIR)/$(TARGET)

docs: $(DOC_OUTPUT)

$(DOC_OUTPUT): $(DOC_SOURCE)
	@mkdir -p $(BUILD_DIR)
	@echo "Сборка документации..."
	@typst compile --root .. $< $@

clean:
	@echo "Очистка проекта..."
	@rm -rf $(BUILD_DIR)
	@rm -f $(MAKEFILE_QT)
	@rm -f .qmake.stash
