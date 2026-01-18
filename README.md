# Otto DIY Robot

A custom Otto robot build using Arduino Nano ESP32.

## Hardware

- Arduino Nano ESP32
- 2x MG90S Servo Motors (metal gear, for legs)

## Wiring

| Servo      | Arduino Pin | GPIO |
|------------|-------------|------|
| Left Leg   | D2          | 5    |
| Right Leg  | D3          | 6    |

**Power:** Use external 5V power for servos (USB power may not be sufficient).

## Dependencies

Install via Arduino IDE Library Manager:
- **ESP32Servo** by Kevin Harrington

## Upload

1. Select board: **Arduino Nano ESP32**
2. Select port
3. Upload sketch

## Serial Commands

Open Serial Monitor at 115200 baud:
- `h` - Home position
- `w` - Walk (4 steps)
- `l` - Lean left
- `r` - Lean right

## References

- [OttoDIY Library](https://github.com/OttoDIY/OttoDIYLib)
- [Otto DIY Website](https://www.ottodiy.com/)
