# Variables
JAVAC = javac
KOTLINC = kotlinc
CLOJUREC = clojure

JAVA_SOURCES = $(wildcard Java/*.java)
KOTLIN_SOURCES = $(wildcard Kotlin/*.kt)
CLOJURE_SOURCES = $(wildcard Clojure/*.clj)

JAVA_CLASSES = $(JAVA_SOURCES:.java=.class)
KOTLIN_CLASSES = $(KOTLIN_SOURCES:.kt=.class)

# Default target
all: java kotlin clojure

java: $(JAVA_CLASSES)

kotlin: $(KOTLIN_CLASSES)

clojure: $(CLOJURE_SOURCES)
	$(CLOJUREC) $<

%.class: %.java
	$(JAVAC) $<
	mv Java/hello.class .

%.class: %.kt
	$(KOTLINC) $< -include-runtime -d $(@:.class=.jar)
	mv Kotlin/hello.jar .

clean:
	rm -f *.class
	rm -f *.jar
	rm -f Java/*.class
	rm -f Kotlin/*.class