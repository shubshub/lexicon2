An Open Source Text Based Game Engine written in C++

This engine is designed to facillitate the development of Room based Text Adventures
Future formats may be supported in the future, But for now just Room based Text Adventures


Usage in your project
```
#include "engine/engine.h"
```

Just include the engine/engine.h file in your Project and you will get access to the entire Lexicon2 Engine

Engine API
```
Parseley3 _parseley = Parseley3();
```
Once you have included the engine, We need to create some essentials for the Game Engine to Run correctly
We will create a Parseley3 instance which holds everything related to taking in User Input and translating it to actions in the game

```
Verb _verb = Verb("walk");
```
Verbs are essential for any Text Based Game, If you want to define a word that will be picked up from the User Input to create an action you would define it here
For example: "walk over to the table"

Now if you have defined a method to be executed, Which we can do by defining a Preposition
```
void walkPrep(Entity* _entity, Lexicon2* engine) {
    std::cout << "You walk over to the " << _entity->GetName();
}

Preposition _to;
_to.prep = "to";
_to.function = walkPrep;
_verb.AddPreposition(&_to);
```

You can see we declared Preposition _tol And then assigned it the walkPrep method, And then added the Preposition to our verb
This first Preposition you add will act as the default Preposition to be executed if the User does not enter any Prepositions

For example with just this Preposition
"walk over to the table" and "walk table" and "walk around the table"
Will all execute that same code

Lets add a second Prepoisition
```
void besidePrep(Entity* _entity, Lexicon2* engine) {
    std::cout << "You walk beside the " << _entity->GetName();
}

Preposition _beside;
_beside.prep = "beside";
_beside.function = besidePrep;
_verb.AddPreposition(&_beside);
```

Now if we were to type "walk beside the table" It will execute that Method instead of the one we setup for the "to" Preposition
