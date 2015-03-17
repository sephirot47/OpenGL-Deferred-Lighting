#ifndef TIME_H
#define TIME_H

#include <SDL2/SDL.h>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;
class Time
{
public:

    ///\brief Returns the time in seconds since the engine started
    static float GetSeconds(); //Retorna Segons des de que s'inicia SDL

    ///\brief Returns the time in milisecs since the engine started
    static long GetMiliseconds(); //Retorna Milisegons des de que s'inicia SDL

	static string GetDateStr();
};
#endif // TIME_H
