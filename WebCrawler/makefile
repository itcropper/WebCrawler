

EXE = bin/crawler
EXET = bin/test
Lib_util_inc = utils/inc
Lib_util_src = utils/src
Lib_util_obj = utils/obj
TESTCS = http://students.cs.byu.edu/~cs240ta/crawler_tests/crawlindex.html
TESTLight = http://lightplanet.com/mormons/people/joseph_smith/index.html
TESTDOSE = http://adoseoflovely.blogspot.com/
TESTFILE = http://students.cs.byu.edu/~cs240ta/fall2011/projects/crawler/graphs/local.svg
SUPP = string.supp
OUT = out.xml
STOP = stopwords.txt
OBJSMain = obj/Description.o obj/LinkQueue.o obj/LinkHistory.o obj/main.o obj/HTMLParser.o obj/Occurence.o obj/Page.o obj/StopWords.o \
obj/URL_Resolver.o obj/PageDownloader.o obj/PageList.o obj/Word.o obj/WordIndex.o obj/Write.o obj/Webcrawler.o

OBJSTest = obj/Description.o obj/LinkQueue.o obj/LinkHistory.o obj/HTMLParser.o obj/Occurence.o obj/Page.o obj/StopWords.o \
obj/URL_Resolver.o obj/PageDownloader.o obj/PageList.o obj/Word.o obj/WordIndex.o obj/Write.o obj/Webcrawler.o obj/test.o

# ./bin/webc http://students.cs.byu.edu/~cs240ta/crawler_tests/crawlindex.html out.txt stopwords.txt
# ./bin/webc  http://adoseoflovely.blogspot.com/ out.txt stopwords.txt


bin : lib webber

test : 	lib tester
	@ ./$(EXET) $(TESTCS) $(OUT) $(STOP)
	
runcs: $(EXE)
	@ ./$(EXE) $(TESTCS) $(OUT) $(STOP)
	
rundose :  $(EXE)
	@ ./$(EXE) $(TESTDOSE) $(OUT) $(STOP)
	
runlight :   $(EXE)
	@ ./$(EXE) $(TESTLight) $(OUT) $(STOP)

runfile : $(EXE)
	@ ./$(EXE) $(TESTFILE) $(OUT) $(STOP)

vallight : $(EXE)
	@ valgrind --tool=memcheck --leak-check=yes --max-stackframe=5000000 --show-reachable=yes --suppressions=$(SUPP)  \
$(EXE) $(TESTLight) $(OUT) $(STOP)

valcs : $(EXE)
	@ valgrind --tool=memcheck --leak-check=yes --max-stackframe=5000000 --show-reachable=yes --suppressions=$(SUPP)  \
$(EXE) $(TESTCS) $(OUT) $(STOP)


clean   :
	@ echo "Removing files"
	@- rm $(Lib_util_obj)/*.o	
	@- rm lib/*.a 			
	@- rm bin/* 			
	@- rm obj/*


webber: $(EXE)

$(EXE): $(OBJSMain) lib/libcs240utils.a
	g++ -o bin/crawler -g -O0 $(OBJSMain) lib/libcs240utils.a
	
tester : $(EXET)
	
$(EXET): $(OBJSTest) lib/libcs240utils.a
	g++ -o bin/test -g -O0 $(OBJSTest) lib/libcs240utils.a	

	
lib/web.a: obj/Webcrawler.o obj/LinkQue.o
	ar r lib/web.a obj/Webcrawler.o obj/LinkQue.o obj/LinkHistory.o




obj/Description.o: src/Description.cpp inc/Description.h 
	g++ -o obj/Description.o -Wall -g -c -I inc -I utils/inc src/Description.cpp 

obj/HTMLParser.o: src/HTMLParser.cpp inc/HTMLParser.h 
	g++ -o obj/HTMLParser.o -Wall -g -c -I inc -I utils/inc src/HTMLParser.cpp 

obj/LinkedList.h: src/LinkedList.o inc/LinkedList.h
	g++ -o obj/LinkedList.h -Wall -g -c -I inc src/LinkedList.h

obj/LinkQueue.o	: src/LinkQueue.cpp inc/LinkQueue.h
	g++ -o obj/LinkQueue.o -Wall -g -c -I inc src/LinkQueue.cpp 

obj/LinkHistory.o: src/LinkHistory.cpp inc/LinkHistory.h
	g++ -o obj/LinkHistory.o -Wall -g -c -I inc -I utils/inc src/LinkHistory.cpp 

obj/main.o: src/main.cpp
	g++ -o obj/main.o -Wall -g -c -I inc -I utils/inc src/main.cpp

obj/Occurence.o: src/Occurence.cpp inc/Occurence.h 
	g++ -o obj/Occurence.o -Wall -g -c -I inc -I utils/inc src/Occurence.cpp 

obj/OccurenceSet.o: src/OccurenceSet.cpp inc/OccurenceSet.h 
	g++ -o obj/OccurenceSet.o -Wall -g -c -I inc -I utils/inc src/OccurenceSet.cpp 

obj/Page.o: src/Page.cpp inc/Page.h 
	g++ -o obj/Page.o -Wall -g -c -I utils/inc -I inc src/Page.cpp 

obj/PageDownloader.o: src/PageDownloader.cpp inc/PageDownloader.h 
	g++ -o obj/PageDownloader.o -Wall -g -c -I inc -I utils/inc src/PageDownloader.cpp 

obj/PageList.o	: src/PageList.cpp inc/PageList.h 
	g++ -o obj/PageList.o -Wall -g -c -I inc -I utils/inc src/PageList.cpp 

obj/StopWords.o: src/StopWords.cpp inc/StopWords.h 
	g++ -o obj/StopWords.o -Wall -g -c -I utils/inc -I inc src/StopWords.cpp 
	
obj/test.o: src/test.cpp
	g++ -o obj/test.o -Wall -g -c -I utils/inc -I inc src/test.cpp 

obj/URL.o: src/URL.cpp inc/URL.h 
	g++ -o obj/URL.o -Wall -g -c -I inc src/URL.cpp 
	
obj/URL_Resolver.o: src/URL_Resolver.cpp inc/URL_Resolver.h 
	g++ -o obj/URL_Resolver.o -Wall -g -c -I utils/inc -I inc src/URL_Resolver.cpp 

obj/Webcrawler.o: src/Webcrawler.cpp inc/Webcrawler.h
	g++ -o obj/Webcrawler.o -Wall -g  -c -I inc -I utils/inc src/Webcrawler.cpp
	
obj/Word.o: src/Word.cpp inc/Word.h
	g++ -o obj/Word.o -Wall -g  -c -I  inc -I utils/inc src/Word.cpp	

obj/WordIndex.o: src/WordIndex.cpp inc/WordIndex.h
	g++ -o obj/WordIndex.o -Wall -g  -c -I  inc -I utils/inc src/WordIndex.cpp
bug :  bin
	@ ./$(EXE) $(TESTCS) $(OUT) $(STOP)
obj/WordIndexParser.o: src/WordIndexParser.cpp inc/WordIndexParser.h
	g++ -o obj/WordIndexParser.o -Wall -g  -c -I  inc -I utils/inc src/WordIndexParser.cpp

obj/Write.o: src/Write.cpp inc/Write.h
	g++ -o obj/Write.o -Wall -g  -c -I  inc -I utils/inc src/Write.cpp


lib : lib/libcs240utils.a

lib/libcs240utils.a : $(Lib_util_obj)/CommandRunner.o $(Lib_util_obj)/FileInputStream.o $(Lib_util_obj)/FileSystem.o $(Lib_util_obj)/HTTPInputStream.o\
$(Lib_util_obj)/HTMLToken.o $(Lib_util_obj)/URLInputStream.o $(Lib_util_obj)/HTMLTokenizer.o $(Lib_util_obj)/StringUtil.o
	ar r lib/libcs240utils.a $(Lib_util_obj)/*.o


$(Lib_util_obj)/CommandRunner.o: $(Lib_util_src)/CommandRunner.cpp $(Lib_util_inc)/CommandRunner.h $(Lib_util_inc)/CS240Exception.h $(Lib_util_inc)/StringUtil.h
	g++ -o $(Lib_util_obj)/CommandRunner.o -g -c -I $(Lib_util_inc) $(Lib_util_src)/CommandRunner.cpp


$(Lib_util_obj)/FileInputStream.o: $(Lib_util_src)/FileInputStream.cpp $(Lib_util_inc)/FileInputStream.h $(Lib_util_inc)/InputStream.h $(Lib_util_inc)/CS240Exception.h
	g++ -o $(Lib_util_obj)/FileInputStream.o -g -c -I $(Lib_util_inc) $(Lib_util_src)/FileInputStream.cpp


$(Lib_util_obj)/FileSystem.o: $(Lib_util_src)/FileSystem.cpp $(Lib_util_inc)/FileSystem.h $(Lib_util_inc)/CS240Exception.h $(Lib_util_inc)/UnitTest.h
	g++ -o $(Lib_util_obj)/FileSystem.o -g -c -I  $(Lib_util_inc) $(Lib_util_src)/FileSystem.cpp


$(Lib_util_obj)/HTTPInputStream.o: $(Lib_util_src)/HTTPInputStream.cpp $(Lib_util_inc)/HTTPInputStream.h $(Lib_util_inc)/InputStream.h $(Lib_util_inc)/CS240Exception.h
	g++ -o $(Lib_util_obj)/HTTPInputStream.o -g -c -I utils/inc $(Lib_util_src)/HTTPInputStream.cpp


$(Lib_util_obj)/HTMLToken.o: $(Lib_util_src)/HTMLToken.cpp $(Lib_util_inc)/HTMLToken.h
	g++ -o $(Lib_util_obj)/HTMLToken.o -g -c -I  $(Lib_util_inc) $(Lib_util_src)/HTMLToken.cpp

$(Lib_util_obj)/URLInputStream.o: $(Lib_util_src)/URLInputStream.cpp $(Lib_util_inc)/URLInputStream.h
	g++ -o $(Lib_util_obj)/URLInputStream.o -g -c -I  $(Lib_util_inc) $(Lib_util_src)/URLInputStream.cpp

$(Lib_util_obj)/HTMLTokenizer.o: $(Lib_util_src)/HTMLTokenizer.cpp $(Lib_util_inc)/HTMLTokenizer.h
	g++ -o $(Lib_util_obj)/HTMLTokenizer.o -g -c -I  $(Lib_util_inc) $(Lib_util_src)/HTMLTokenizer.cpp

$(Lib_util_obj)/StringUtil.o: $(Lib_util_src)/StringUtil.cpp $(Lib_util_inc)/StringUtil.h
	g++ -o $(Lib_util_obj)/StringUtil.o -g -c -I  $(Lib_util_inc) $(Lib_util_src)/StringUtil.cpp


