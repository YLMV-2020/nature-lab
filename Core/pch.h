// pch.h: este es un archivo de encabezado precompilado.
// Los archivos que se muestran a continuación se compilan solo una vez, lo que mejora el rendimiento de la compilación en futuras compilaciones.
// Esto también afecta al rendimiento de IntelliSense, incluida la integridad del código y muchas funciones de exploración del código.
// Sin embargo, los archivos que se muestran aquí se vuelven TODOS a compilar si alguno de ellos se actualiza entre compilaciones.
// No agregue aquí los archivos que se vayan a actualizar con frecuencia, ya que esto invalida la ventaja de rendimiento.

#ifndef PCH_H
#define PCH_H

// agregue aquí los encabezados que desea precompilar
#include "framework.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Core.h"

#ifdef FX_PLATFORM_WINDOWS
	#include <Windows.h>
#endif

#endif //PCH_H
