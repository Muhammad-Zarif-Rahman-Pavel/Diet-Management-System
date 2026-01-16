# Diet-Management-System

# Project Outline 
**Based on Age & BMI (C Language)**

---

## Project Goal
To develop a console-based application in **C** that calculates a user's **Body Mass Index (BMI)**, determines their **ideal calorie intake** based on age and BMI classification, and provides **simplified, text-based dietary and exercise recommendations**.

---

## Features

### 1. User Input Module
- Collect necessary user data:
  - Age (in years)
  - Gender
  - Height (in meters or feet & inches)
  - Weight (in kilograms or pounds)
- Implement robust input validation:
  - Ensure age and measurements are positive numbers.

---

### 2. BMI Calculation Function
- Implement the standard BMI formula:

  \[
  BMI = \frac{Weight\ (kg)}{Height\ (m)^2}
  \]

- Convert input units if necessary:
  - Pounds → Kilograms
  - Inches/Feet → Meters

---

### 3. Classification Logic
- **BMI Classification**:
  - Use `if-else` or `switch` statements.
  - Categories:
    - Underweight
    - Normal
    - Overweight
    - Obese
- **Age-Specific Classification**:
  - Classify users into life stages:
    - Child/Teen
    - Adult
    - Senior
  - Used as the basis for different recommendation standards.

---

### 4. Calorie Needs Estimation (Simplified TDEE)
- Implement a simplified method such as:
  - **Harris-Benedict Equation**, or
  - **Mifflin-St Jeor Equation**
- Calculate **Basal Metabolic Rate (BMR)**.
- Factor in an assumed **Activity Level** to compute:
  - **Total Daily Energy Expenditure (TDEE)**
- Adjust calorie goals based on BMI classification:
  - Example: Subtract 500 calories for weight loss in the *Overweight* category.

---

### 5. Diet Recommendation Engine
- Provide high-level textual recommendations based on:
  - Calorie intake
  - BMI classification

**Examples:**
- **Underweight**:
  - Focus on nutrient-dense foods.
  - Recommend higher protein and calorie snacks.
- **Normal / Maintenance**:
  - Emphasize balanced macronutrients.
  - Encourage adequate hydration.

---

### 6. Exercise Recommendation Module
- Provide text-based exercise suggestions based on:
  - BMI classification
  - Weight goal

**Examples:**
- Overweight:
  - Daily low-impact cardio.
- Normal weight:
  - Strength training 3 times per week.

- Include age-appropriate guidance:
  - Seniors: Focus on flexibility and balance.
  - Children: Emphasize play-based physical activity.

---

### 7. Data Persistence (File Handling)
- Allow users to save their profile:
  - Age
  - Height
  - Weight
  - BMI
- Store data in a simple file format:
  - `.txt` or `.dat`
- Use standard C file I/O functions:
  - `fopen`
  - `fprintf`
  - `fscanf`

---

### 8. Menu-Driven Interface
- Provide a clear main menu:
  1. Calculate BMI  
  2. Get Recommendation  
  3. View Saved Profile  
  4. Exit  

---

## Advantages of Using C for This Project

| Advantage | Description |
|---------|------------|
| **Fundamental Skill Building** | Practice core C concepts: functions, structs, pointers, and file handling. |
| **Efficiency and Speed** | Fast execution of mathematical calculations (BMI, BMR). |
| **Control Over Memory** | Teaches manual memory management, essential for system programming. |
| **Portability** | Executables can run on Windows, Linux, and macOS with minimal changes. |
| **Modular Design** | Naturally supports function-based, well-structured program design. |

---

## Disadvantages & Limitations (Due to C and Scope)

| Disadvantage | Description |
|-------------|------------|
| **Text-Based User Interface** | Limited to a command-line interface (CLI) with no graphical elements. |
| **Simplified Recommendations** | Cannot easily support large food databases or personalized meal plans. |
| **No Real-Time Data / APIs** | Lacks easy integration with modern web APIs or health trackers. |
| **Data Handling Complexity** | Flat file storage is less robust than modern databases. |
| **Limited Error Debugging** | Debugging memory and pointer issues can be challenging. |

---

## Conclusion
This project outline defines a **balanced and comprehensive scope** for a C-based Diet Management System. By implementing the listed features, the developer gains valuable experience in:

- Mathematical computation  
- Conditional logic  
- Struct-based data handling  
- File I/O operations  

# How to Run the code
- First of Download or Clone the the Project
- Make sure lates virsion of GCC installed
- Use a Code Editor to run the code.
- For VS Code use a Code runner Extention
- For Codeblocks just click build and run
