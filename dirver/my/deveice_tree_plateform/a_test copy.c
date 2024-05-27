#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of.h>

struct example_dev {
    struct device *dev;
    int some_resource;
};

static int example_probe(struct platform_device *pdev)
{
    struct example_dev *dev;
    struct resource *res;

    dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);
    if (!dev)
        return -ENOMEM;

    dev->dev = &pdev->dev;

    res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
    if (!res) {
        dev_err(&pdev->dev, "No memory resource found\n");
        return -ENODEV;
    }

    dev->some_resource = res->start; // Example resource usage

    dev_info(&pdev->dev, "Example device probed\n");
    return 0;
}

static int example_remove(struct platform_device *pdev)
{
    dev_info(&pdev->dev, "Example device removed\n");
    return 0;
}

static const struct of_device_id example_of_match[] = {
    { .compatible = "fire,rgb_led_red", },
    {},
};
MODULE_DEVICE_TABLE(of, example_of_match);

static struct platform_driver example_driver = {
    .probe = example_probe,
    .remove = example_remove,
    .driver = {
        .name = "example_driver",
        .of_match_table = example_of_match,
    },
};

module_platform_driver(example_driver);

MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Example Platform Driver");
MODULE_LICENSE("GPL");
