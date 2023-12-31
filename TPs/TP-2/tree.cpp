// Code de methode

#include "tree.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

Tree::Tree(){
    cout << "Construire " << this << endl;
}

void Tree::draw(){

    const char* arbol[4] = {R"(         . . .
       .        .  .     ..    .
    .                 .         .  .
                    .
                   .                ..
   .          .            .              .
   .            '.,        .               .
   .              'b      *
    .              '$    #.                ..
   .    .           $:   #:               .
 ..      .  ..      *#  @):        .   . .
              .     :@,@):   ,.**:'   .
  .      .,         :@@*: ..**'      .   .
           '#o.    .:(@'.@*"'  .
   .  .       'bq,..:,@@*'   ,*      .  .
              ,p$q8,:@)'  .p*'      .
       .     '  . '@@Pp@@*'    .  .
        .  . ..    Y7'.'     .  .
                  :@):.
                 .:@:'.
               .::(@:.      )",R"(         - - -
       -        -  -     --    -
    -                 -         -  -
                    -
                   -                --
   -          -            -              -
   -            '-,        -               -
   -              'b      *
    -              '$    #-                --
   -    -           $:   #:               -
 --      -  --      *#  @):        -   - -
              -     :@,@):   ,-**:'   -
  -      -,         :@@*: --**'      -   -
           '#o-    -:(@'-@*"'  -
   -  -       'bq,--:,@@*'   ,*      -  -
              ,p$q8,:@)'  -p*'      -
       -     '  - '@@Pp@@*'    -  -
        -  - --    Y7'.'     -  -
                  :@):.
                 .:@:'.
               .::(@:.      )",R"(         / / /
       /        /  /     //    /
    /                 /         /  /
                    /
                   /                //
   /          /            /              /
   /            '/,        /               /
   /              'b      *
    /              '$    //                //
   /    /           $:   /:               /
 //      /  //      */  @):        /   / /
              /     :@,@):   ,/**:'   /
  /      /,         :@@*: //**'      /   /
           '/o/    /:(@'/@*"'  /
   /  /       'bq,//:,@@*'   ,*      /  /
              ,p$q8,:@)'  /p*'      /
       /     '  / '@@Pp@@*'    /  /
        /  / //    Y7'.'     /  /
                  :@):.
                 .:@:'.
               .::(@:.      )",R"(         ; ; ;
       ;        ;  ;     ;;    ;
    ;                 ;         ;  ;
                    ;
                   ;                ;;
   ;          ;            ;              ;
   ;            ';,        ;               ;
   ;              'b      *
    ;              '$    ;;                ;;
   ;    ;           $:   ;:               ;
 ;;      ;  ;;      *;  @):        ;   ; ;
              ;     :@,@):   ,;**:'   ;
  ;      ;,         :@@*: ;;**'      ;   ;
           ';o;    ;:(@';@*"'  ;
   ;  ;       'bq,;;:,@@*'   ,*      ;  ;
              ,p$q8,:@)'  ;p*'      ;
       ;     '  ; '@@Pp@@*'    ;  ;
        ;  ; ;;    Y7'.'     ;  ;
                  :@):.
                 .:@:'.
               .::(@:.      )"};

    for (int i = 1; i % 5; i++){
        cout << arbol[i-1] << endl;
	    this_thread::sleep_for(chrono::milliseconds(300));
        system("clear");
        if (i == 4){
            i = 0;
        }   
    }
    
}

Tree::~Tree(){ // Ultima wea que haces antes de destruir
    cout << "Deconstruire " << this <<endl;
}
