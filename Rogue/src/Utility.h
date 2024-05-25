#pragma once

#define START_GAME(className) \
int main()\
{\
	className _game;\
	_game.Run();\
	return 0;\
}


#ifdef ROGUE_MS_COMPILER		
	#ifdef ROGUE_LIB
		#define ROGUE_API __declspec(dllexport)
	#else
		#define ROGUE_API __declspec(dllimport)
	#endif
#else
	#define ROGUE_API
#endif


#if ROGUE_DEBUG==2
	#define ROGUE_ERROR(x) std::cout<<x<<std::endl;
	#define ROGUE_LOG(x) std::cout<<x<<std::endl;
#elif ROGUE_DEBUG==1
	#define ROGUE_ERROR(x) std::cout<<x<<std::endl;
	#define ROGUE_LOG(x) std::cout<<x<<std::endl;
#else
	#define ROGUE_ERROR(x) 
	#define ROGUE_LOG(x)
#endif