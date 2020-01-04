#pragma once
#define RELEASE(x) if((x) != nullptr){ delete (x); (x) = nullptr; }