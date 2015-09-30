#include "TestWrapper.h"

// implementation code of WrapperFactory - do NOT modify the next 5 lines
AbstractWrapper* WrapperFactory::wrapper = 0;
AbstractWrapper* WrapperFactory::createWrapper() {
  if (wrapper == 0) wrapper = new TestWrapper;
  return wrapper;
}
// Do not modify the following line
volatile bool TestWrapper::GlobalStop = false;

// a default constructor
TestWrapper::TestWrapper() {
  // create any objects here as instance variables of this class
  // as well as any initialization required for your spa program
}

// method for parsing the SIMPLE source
void TestWrapper::parse(std::string filename) {
	// call your parser to do the parsing
    // ...rest of your code...
	Parser *p = new Parser();
	vector<string> tokenizedProgram = (*p).parseSimpleProgram(filename);

	if (tokenizedProgram.size() > 0) {
		Database *db = new Database();
		db->buildDatabase(tokenizedProgram);
		cout << "Successfully constructed AST.\n";
		
		//viewAST(db->printAbstractSyntaxTree(db->getAbstractSyntaxTreeRoot()), filename);
		pkbPointer = ProgramKnowledgeBase(db);

		cout << "Successfully constructed PKB.\n";
	}
	else {
		cout << "Could not parse SIMPLE program. Aborting.\n";
	}

}

// method to evaluating a query
void TestWrapper::evaluate(std::string query, std::list<std::string>& results){
// call your evaluator to evaluate the query here
  // ...code to evaluate query...

	QueryEvaluator qe = QueryEvaluator(pkbPointer);	
	results = qe.getResults(query);
  // store the answers to the query in the results list (it is initially empty)
  // each result must be a string.
}
