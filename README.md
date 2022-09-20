# clox
Bytecode Compiler in C.


# Interpreter Architecture
    Scanner => Compiler => Virtual Machine
 
        Input			Process			Output
        ------			-------			------
     SourceCode ->	    Scanner		->	Tokens  
     Token	->		    Compiler	->	Bytecode Chunk
     Bytecode	->		VM			->	"Runs Program"



