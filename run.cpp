#include "vk.hpp"

void Vulkan::run( vk_param& param ) {
	try {
		std::cout << MAGNETA << "start vulkan.run()\n" << RESET;
		createInstance( param );
		createSurface( param.window );
		pickPhysicalDevice();
		createLogicalDevice();
		std::cout << MAGNETA << "custom end vulkan.run()\n" << RESET;

	} catch( su::custom_exception& ex ) {
		std::cout << YELLOW << "custom param error. started with default parameters...\n" << RESET;
#ifdef VK_DEBUG_L1_
		std::cout << YELLOW << "error in Vulkan::run()\n";
		std::cout << "\tsu::custom_exception\n";
		std::cout << "\ttype: " << ex.getType() << "\n";
		std::cout << "\tmsg: " << ex.getMsg() << "\n";
		std::cout << "\tcode: " << ex.getCode() << "\n" << RESET;
#endif
		param.enableValidationLayers = true;
		param.validationLayers = { "VK_LAYER_KHRONOS_validation" };

		createInstance( param );
		createSurface( param.window );
		pickPhysicalDevice();
		createLogicalDevice();
		std::cout << MAGNETA << "default end vulkan.run()\n" << RESET;

	} catch( std::exception& ex ) {
		throw std::runtime_error( ex.what() );
	} catch(...) {
		throw std::runtime_error("unknown error.\n");
	}
}
