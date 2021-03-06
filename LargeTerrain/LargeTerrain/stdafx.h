// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 특정 포함 파일이 들어 있는
// 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>


#include <wrl.h>
#include <dxgi1_4.h>
#include <d3d12.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <DirectXColors.h>
#include <DirectXCollision.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>



// 여기서 프로그램에 필요한 추가 헤더를 참조합니다.
#include <memory>
#include <vector>
#include <string>
#include <array>
#include <iostream>
#include <list>
#include <algorithm>
#include <random>
#include <stdint.h>
#include <optional>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <chrono>
#include <thread>
#include <mutex>
#include <ppl.h>
#include <cmath>


#include "boost/unordered_map.hpp"


#include "rx.hpp"
#include "cpplinq.hpp"

#include "Default/Define.h"
#include "Default/Singleton.h"
#include "Default/Timer.h"