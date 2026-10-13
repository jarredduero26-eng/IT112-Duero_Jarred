#include <stdio.h>

/* Function declarations */
void displayTitle(void);
int getWeatherChoice(void);
int getRainChance(void);
int getTransportChoice(void);
int getCommuteMinutes(void);
int getElectronicsChoice(void);

int calculateRiskScore(int weather, int rainChance,
                       int transport, int commuteMinutes,
                       int electronics);

void showRecommendations(int weather, int riskScore,
                         int transport, int commuteMinutes,
                         int electronics, int rainChance);

void showReminders(void);

int main(void)
{
    char studentName[50];
    int weather, rainChance, transport;
    int commuteMinutes, electronics;
    int riskScore, again;

    do
    {
        displayTitle();

        printf("Enter your name: ");
        scanf("%49s", studentName);

        printf("\nHello, %s!\n", studentName);

        weather = getWeatherChoice();
        rainChance = getRainChance();
        transport = getTransportChoice();
        commuteMinutes = getCommuteMinutes();
        electronics = getElectronicsChoice();

        riskScore = calculateRiskScore(
            weather, rainChance, transport,
            commuteMinutes, electronics
        );

        printf("\n====================================\n");
        printf("       YOUR PREPARATION REPORT\n");
        printf("====================================\n");

        printf("Student: %s\n", studentName);

        printf("Weather: ");
        switch (weather)
        {
            case 1: printf("Sunny\n"); break;
            case 2: printf("Cloudy\n"); break;
            case 3: printf("Light Rain\n"); break;
            case 4: printf("Heavy Rain\n"); break;
        }

        printf("Chance of rain: %d%%\n", rainChance);
        printf("Travel time: %d minutes\n", commuteMinutes);

        printf("Transportation: ");
        switch (transport)
        {
            case 1: printf("Walking\n"); break;
            case 2: printf("Bicycle or motorcycle\n"); break;
            case 3: printf("Car, bus, or covered transport\n"); break;
        }

        printf("Electronics carried: %s\n",
               electronics == 1 ? "Yes" : "No");

        printf("\nPreparation priority score: %d/100\n",
               riskScore);

        showRecommendations(
            weather, riskScore, transport,
            commuteMinutes, electronics, rainChance
        );

        showReminders();

        printf("\nWould you like to use RainReady again?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice: ");

        scanf("%d", &again);

        while (again != 1 && again != 2)
        {
            printf("Invalid choice. Enter 1 or 2: ");
            scanf("%d", &again);
        }

    } while (again == 1);

    printf("\nThank you for using RainReady!\n");

    return 0;
}

/* Displays the program title */
void displayTitle(void)
{
    printf("\n====================================\n");
    printf("          RAINREADY 2.0\n");
    printf("  Personalized Weather Preparation\n");
    printf("====================================\n");
}

/* Gets and validates the weather choice */
int getWeatherChoice(void)
{
    int weather;

    printf("\nHow is the weather today?\n");
    printf("1. Sunny\n");
    printf("2. Cloudy\n");
    printf("3. Light Rain\n");
    printf("4. Heavy Rain\n");
    printf("Enter your choice: ");
    scanf("%d", &weather);

    while (weather < 1 || weather > 4)
    {
        printf("Invalid choice. Enter 1 to 4: ");
        scanf("%d", &weather);
    }

    return weather;
}

/* Gets the chance of rain */
int getRainChance(void)
{
    int chance;

    printf("\nEnter the chance of rain (0-100): ");
    scanf("%d", &chance);

    while (chance < 0 || chance > 100)
    {
        printf("Invalid percentage. Enter 0 to 100: ");
        scanf("%d", &chance);
    }

    return chance;
}

/* Gets the user's transportation method */
int getTransportChoice(void)
{
    int transport;

    printf("\nHow do you travel to school?\n");
    printf("1. Walking\n");
    printf("2. Bicycle or motorcycle\n");
    printf("3. Car, bus, or covered transport\n");
    printf("Enter your choice: ");
    scanf("%d", &transport);

    while (transport < 1 || transport > 3)
    {
        printf("Invalid choice. Enter 1 to 3: ");
        scanf("%d", &transport);
    }

    return transport;
}

/* Gets the travel duration */
int getCommuteMinutes(void)
{
    int minutes;

    printf("\nHow many minutes is your trip to school (1-180)? ");
    scanf("%d", &minutes);

    while (minutes < 1 || minutes > 180)
    {
        printf("Enter a travel time from 1 to 180 minutes: ");
        scanf("%d", &minutes);
    }

    return minutes;
}

/* Checks whether the student carries electronics */
int getElectronicsChoice(void)
{
    int choice;

    printf("\nAre you carrying a phone, tablet, or laptop?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice < 1 || choice > 2)
    {
        printf("Invalid choice. Enter 1 or 2: ");
        scanf("%d", &choice);
    }

    return choice == 1;
}

/* Calculates a preparation priority score */
int calculateRiskScore(int weather, int rainChance,
                       int transport, int commuteMinutes,
                       int electronics)
{
    int score = rainChance * 45 / 100;

    /* Additional points based on weather */
    switch (weather)
    {
        case 1: score += 0;  break;
        case 2: score += 5;  break;
        case 3: score += 15; break;
        case 4: score += 30; break;
    }

    /* Longer trips mean more exposure */
    if (commuteMinutes > 30)
        score += 20;
    else if (commuteMinutes > 10)
        score += 10;
    else
        score += 5;

    /* Consider exposure during transportation */
    if (transport == 1)
        score += 10;
    else if (transport == 2)
        score += 20;

    /* Consider belongings that need protection */
    if (electronics == 1)
        score += 10;

    /* Keep the score within 0-100 */
    if (score > 100)
        score = 100;

    return score;
}

/* Gives personalized advice and explains possible problems */
void showRecommendations(int weather, int riskScore,
                         int transport, int commuteMinutes,
                         int electronics, int rainChance)
{
    printf("\n--- POSSIBLE PROBLEMS AND SOLUTIONS ---\n");

    if (weather == 1)
    {
        printf("Possible problem: Heat and dehydration.\n");
        printf("Action: Bring water and avoid excessive sun exposure.\n");
    }
    else if (weather == 2)
    {
        printf("Possible problem: Weather may change during your trip.\n");
        printf("Action: Check an updated forecast before leaving.\n");
    }
    else if (weather == 3)
    {
        printf("Possible problem: Wet clothes and school materials.\n");
        printf("Action: Bring an umbrella or raincoat.\n");
    }
    else
    {
        printf("Possible problem: Poor visibility, slippery roads, "
               "and possible travel delays.\n");
        printf("Action: Check official weather and local safety "
               "advisories before travelling.\n");
    }

    if (transport == 1)
    {
        printf("\nWalking-specific advice:\n");
        printf("- Use safe walking routes and avoid slippery areas.\n");
    }
    else if (transport == 2)
    {
        printf("\nBicycle/motorcycle advice:\n");
        printf("- Wet roads can reduce traction and visibility.\n");
        printf("- Avoid travelling through flooded roads.\n");
    }
    else
    {
        printf("\nTransport advice:\n");
        printf("- Allow extra time for possible traffic delays.\n");
        printf("- Follow official travel and safety advisories.\n");
    }

    if (commuteMinutes > 30)
    {
        printf("\nLong commute alert:\n");
        printf("- Your trip may involve prolonged weather exposure.\n");
        printf("- Prepare protective items and check conditions "
               "along your route.\n");
    }

    if (electronics == 1)
    {
        printf("\nBelongings alert:\n");
        printf("- Place electronics in a waterproof pouch or bag.\n");
        printf("- Keep devices away from rain and wet surfaces.\n");
    }

    printf("\n--- PREPARATION LEVEL ---\n");

    if (riskScore >= 70)
    {
        printf("HIGH PRIORITY (%d/100)\n", riskScore);
        printf("Review your travel plan and prepare carefully.\n");
    }
    else if (riskScore >= 40)
    {
        printf("MODERATE PRIORITY (%d/100)\n", riskScore);
        printf("Prepare the items relevant to your trip.\n");
    }
    else
    {
        printf("LOW PRIORITY (%d/100)\n", riskScore);
        printf("Continue checking conditions and prepare as needed.\n");
    }

    /* rainChance is now available as a function parameter */
    if (weather == 4 || rainChance >= 70)
    {
        printf("\nIMPORTANT: Check official weather warnings "
               "before leaving.\n");
    }

    printf("Never cross floodwaters or enter an unsafe route.\n");
    printf("Follow official warnings even if your score is low.\n");
}

/* Provides a practical checklist */
void showReminders(void)
{
    printf("\n--- BEFORE LEAVING FOR SCHOOL ---\n");
    printf("1. Check the latest weather forecast and warnings.\n");
    printf("2. Check your umbrella, raincoat, and school bag.\n");
    printf("3. Protect your phone, gadgets, and school materials.\n");
    printf("4. Plan a safe route and allow enough travel time.\n");
    printf("5. Follow school announcements and safety instructions.\n");
}
