#include "VulkanDevice.h"

size_t
TexelGL::Vulkan::Device::getDefaultPhysicalDeviceIndex(void)
{
    return 0;
}

std::shared_ptr <vk::raii::Instance>
TexelGL::Vulkan::Device::createDefaultInstance(std::vector <std::string> const &vulkanInstanceExtensions)
{
    auto const applicationName = std::string();
    auto const applicationVersion = 1;
    auto const engineName = std::string();
    auto const engineVersion = 1;
    auto const applicationInfo = vk::ApplicationInfo(applicationName.c_str(),
                                                     applicationVersion,
                                                     engineName.c_str(),
                                                     engineVersion,
                                                     this->apiVersion);
    auto const validationLayers = std::vector <char const *> {
        "VK_LAYER_KHRONOS_validation",
    };

    auto const defaultVulkanInstanceExtensions = this->getVulkanInstanceExtensions();
    auto vulkanInstanceExtensionPointers = std::vector <char const *> ();

    for (auto const &vulkanInstanceExtension: defaultVulkanInstanceExtensions) {
        vulkanInstanceExtensionPointers.push_back(vulkanInstanceExtension.c_str());
    }

    for (auto const &vulkanInstanceExtension: vulkanInstanceExtensions) {
        vulkanInstanceExtensionPointers.push_back(vulkanInstanceExtension.c_str());
    }

    auto const instanceCreateInformation = vk::InstanceCreateInfo({},
                                                                  &applicationInfo,
                                                                  validationLayers,
                                                                  vulkanInstanceExtensionPointers);
    auto const instance = std::make_shared <vk::raii::Instance> (this->context,
                                                                 instanceCreateInformation);

    return instance;
}

std::shared_ptr <vk::raii::PhysicalDevice>
TexelGL::Vulkan::Device::createDefaultPhysicalDevice(void) const
{
    auto const &physicalDevices = this->instance->enumeratePhysicalDevices();
    auto physicalDevice = std::shared_ptr <vk::raii::PhysicalDevice> (nullptr);

    if (!physicalDevices.empty()) {
        physicalDevice = std::make_shared <vk::raii::PhysicalDevice> (physicalDevices[this->physicalDeviceIndex]);
    }

    return physicalDevice;
}

std::vector <std::string>
TexelGL::Vulkan::Device::getVulkanInstanceExtensions(void) const
{
    auto vulkanInstanceExtensions = std::vector <std::string> {
        VK_KHR_SURFACE_EXTENSION_NAME,
    };

    return vulkanInstanceExtensions;
}

TexelGL::Vulkan::Device::Device(std::vector <std::string> const &vulkanInstanceExtensions) :
    TexelGL::Device::Device(),
    apiVersion(context.enumerateInstanceVersion()),
    instance(Device::createDefaultInstance(vulkanInstanceExtensions)),
    physicalDeviceIndex(Device::getDefaultPhysicalDeviceIndex()),
    physicalDevice(this->createDefaultPhysicalDevice())
{
}

TexelGL::Vulkan::Device::~Device(void)
{
}