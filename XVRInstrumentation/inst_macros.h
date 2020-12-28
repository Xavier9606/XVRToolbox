#pragma once
#include"inst_timer.h"

#define XVR_PROFILE 1

#if XVR_PROFILE

	//MSVC can't do var##__LINE__ by it's own, so we use some macro voodoo
	#define XVR_CONCATENATE_DETAIL(x, y) x##y
	#define XVR_CONCATENATE(x, y) XVR_CONCATENATE_DETAIL(x, y)
	#define XVR_MAKE_UNIQUE_NAME(x) XVR_CONCATENATE(x, __LINE__)
	//----------------------------------------------------------------------

	#define XVR_TRACER_BEGIN_SESSION(name,filepath) ::xvr::inst::tracerJSON::Get().BeginSession(name,filepath);
	#define XVR_TRACER_END_SESSION ::xvr::inst::tracerJSON::Get().EndSession();
	#define XVR_TRACE_SCOPE(name) ::xvr::inst::scoped_timer XVR_MAKE_UNIQUE_NAME(timer)(name)
	#define XVR_TRACE_FUNCTION() XVR_TRACE_SCOPE(__FUNCSIG__)
	#define XVR_PROFILE_SCOPE_CB(name, callback) ::xvr::inst::scoped_timer_cb XVR_MAKE_UNIQUE_NAME(timer)(name, callback)
	#define XVR_PROFILE_FUNCTION_CB(callback) XVR_PROFILE_SCOPE_CB(__FUNCSIG__,callback)
#else	
	#define XVR_PROFILE_BEGIN_SESSION(name) 
	#define XVR_PROFILE_END_SESSION 
	#define XVR_PROFILE_SCOPE(name) 
	#define XVR_PROFILE_FUNCTION()
	#define XVR_PROFILE_SCOPE_CB(name, func) 
	#define XVR_PROFILE_FUNCTION_CB(func) 
#endif