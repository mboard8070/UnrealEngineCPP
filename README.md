# UnrealEngineCPP

# Unreal Engine C++ Code Repository

This repository contains Unreal Engine C++ code for various classes that can be used in game development. The classes included are a floating actor, a light switch, a blueprintable light switch, a custom projectile, a rifle, and an exploding barrel. These classes can serve as a starting point or reference for implementing similar functionality in your own Unreal Engine projects.

## Classes

### Floating Actor

The `FloatingActor` class is an actor that hovers above the ground. It provides a basic floating effect by applying a periodic force to counteract gravity. This class can be extended and customized to create objects that exhibit floating behavior in your game world.

### Light Switch

The `LightSwitch` class represents a switch that can toggle the state of a light source in your game. It provides a simple interface to control the light's visibility or intensity. This class can be used to create interactive light switches that add dynamics to your game environment.

### Blueprintable Light Switch

The `BlueprintableLightSwitch` class is an extension of the `LightSwitch` class, allowing it to be easily customized and controlled through Blueprints in Unreal Engine. It exposes editable properties and events that can be accessed and manipulated directly in the Blueprint editor. This class provides a flexible solution for creating interactive light switches without writing additional C++ code.

### Custom Projectile

The `CustomProjectile` class represents a projectile that can be fired from weapons in your game. It handles the movement and collision detection of the projectile, allowing it to interact with other actors in the game world. This class can be customized to implement specific projectile behaviors, such as damage calculations or visual effects.

### Rifle

The `Rifle` class is a weapon class that simulates a rifle. It provides functionality for firing projectiles, managing ammunition, and reloading. This class can serve as a basis for implementing firearms or other ranged weapons in your game. It can be extended to add additional features, such as different firing modes or weapon attachments.

### Exploding Barrel

The `ExplodingBarrel` class represents a barrel that explodes when triggered. It demonstrates how to create objects with dynamic behavior, such as explosive effects and damage propagation. This class can be used to create interactive and destructible elements in your game world.

## Usage

To use these classes in your Unreal Engine project, follow these steps:

1. Clone or download this repository to your local machine.
2. Open your Unreal Engine project.
3. Copy the desired class files from the repository into your project's source code directory.
4. Recompile your project to include the new classes.
5. In the Unreal Editor, you can now use the new classes in your game levels or Blueprints.

Note: Remember to properly credit and reference this repository if you use the code provided.

## Contributing

Contributions to this repository are welcome! If you have any improvements, bug fixes, or additional classes that you'd like to share, please open a pull request. Be sure to follow the coding style and include appropriate documentation for your changes.

## License

This code is licensed under the [MIT License](LICENSE). Feel free to use and modify the code for your own projects.

## Acknowledgements

- [Unreal Engine](https://www.unrealengine.com/) - The game engine used for development.
- [OpenAI](https://openai.com/) - The organization behind ChatGPT, the AI model that generated this README.

---

Happy coding! If you have any questions or need further assistance, feel free to reach out.
