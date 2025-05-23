#include "vk.hpp"

void Vulkan::pickPhysicalDevice() {
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices( instance, &deviceCount, nullptr );

	if ( !deviceCount ) {
		throw std::runtime_error("failed to find GPUs with Vulkan support.");
	}
	std::vector <VkPhysicalDevice> devices( deviceCount );
	vkEnumeratePhysicalDevices( instance, &deviceCount, devices.data() );

#ifdef VK_DEBUG_info_
	VkPhysicalDeviceProperties deviceProperties;
	vkGetPhysicalDeviceProperties( devices.data()[0], &deviceProperties );
	std::clog << "Device name: " << deviceProperties.deviceName << "\n";
#endif

	physicalDevice = devices.data()[0];
#ifdef VK_DEBUG_notifications_
	std::clog << VK_SUCCESS_COLOR << "pick physicalDevice success!\n" << VK_RESET_COLOR;
#endif
}
