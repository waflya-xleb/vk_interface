#include "vk.hpp"

void Vulkan::run( vk_param& param ) {
#ifdef VK_DEBUG_notifications_
	std::cout << MAGNETA << "start vulkan.run()\n" << RESET;
#endif
	try {
		createInstance( param );
		createSurface( param.window );
		pickPhysicalDevice();
		createLogicalDevice();
#ifdef VK_DEBUG_notifications_
		std::cout << MAGNETA << "custom end vulkan.run()\n" << RESET;
#endif

	} catch( vk::su::custom_exception& ex ) {
#ifdef VK_DEBUG_notifications_
		std::cout << YELLOW << "custom param error. started with default parameters...\n" << RESET;
#endif
#ifdef VK_DEBUG_L1_
		std::cout << YELLOW << "error in Vulkan::run()\n\tvk::su::custom_exception\n\ttype: " << ex.getType() << "\n\tmsg: " << ex.getMsg() << "\n" << RESET;
#endif
		param.enableValidationLayers = true;
		param.validationLayers = { "VK_LAYER_KHRONOS_validation" };

		createInstance( param );
		createSurface( param.window );
		pickPhysicalDevice();
		createLogicalDevice();
#ifdef VK_DEBUG_notifications_
		std::cout << MAGNETA << "default end vulkan.run()\n" << RESET;
#endif

	} catch( std::exception& ex ) {
		throw std::runtime_error( ex.what() );
	} catch(...) {
		throw std::runtime_error("unknown error.\n");
	}
}
