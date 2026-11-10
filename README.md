# SkyShield AI (Bootstrap 5.3.3)

**SkyShield AI: An Intelligent Weather Risk Prediction and Personalized Preparedness System for Students**
Group 5: Jarred D. Duero, Angel May E. Guibelondo, Princess Jewel Salon

A fully offline website built with **Bootstrap 5.3.3**. Students can sign up, log in, check their weather risk and get a personal preparedness plan, all without internet or a server. The risk logic is ported from our C program (RainReady 2.0).

---

## Table of Contents

1. [Features](#1-features)
2. [Quick Start](#2-quick-start)
3. [Project Structure](#3-project-structure)
4. [How the Offline Login Works](#4-how-the-offline-login-works)
5. [How the Risk Score Works](#5-how-the-risk-score-works)
6. [Bootstrap Components Used](#6-bootstrap-components-used)
7. [How to Edit](#7-how-to-edit)
8. [Test Checklist](#8-test-checklist)
9. [Common Mistakes and Fixes](#9-common-mistakes-and-fixes)
10. [Limitations and Credits](#10-limitations-and-credits)

---

## 1. Features

- **Home** and **About the Study** (background, objectives, scope, limitations)
- **Sign Up** and **Login** that work offline
- **Dashboard** with a weather risk checker (rain, thunderstorm, extreme heat)
- Risk score from 0 to 100 classified as **Low**, **Moderate** or **High**
- Personalized recommendations, severe-weather alert and a before-school checklist
- **Recent checks** history saved per account
- Responsive on phones, tablets and computers

---

## 2. Quick Start

1. Use the teacher's template folder (it has the `assets/` folder with Bootstrap files).
2. Replace its `index.html` with our `index.html`. Replace `README.md` with this one.
3. Double-click `index.html` to open it in your browser.
4. Click **Sign Up**, create an account, and the dashboard opens.
5. Change something, save, and refresh (**Ctrl + F5**).

Tip: the **Live Server** extension in VS Code refreshes the page automatically.

---

## 3. Project Structure

```
skyshield-ai/
├── index.html                       The whole website (all pages and logic)
├── assets/
│   ├── css/
│   │   ├── bootstrap.min.css        Bootstrap styles (do NOT edit)
│   │   ├── bootstrap-icons.min.css  Icon styles (do NOT edit)
│   │   ├── fonts/                   Icon fonts
│   │   └── style.css                Custom styles (optional)
│   └── js/
│       └── bootstrap.bundle.min.js  Bootstrap JavaScript (do NOT edit)
└── README.md
```

`index.html` uses hash links (`#home`, `#about`, `#login`, `#signup`, `#dash`) to switch pages, so no `pages/` folder is needed.

---

## 4. How the Offline Login Works

- Accounts are saved in the browser's **localStorage**, so no internet or server is needed.
- Sign Up stores your name, email and a hashed password. Login compares the hash.
- The session is remembered, so you stay logged in after refreshing. **Logout** ends it.
- The Dashboard is protected. Opening `#dash` without logging in sends you to Login.
- Each account has its own history of checks.

Note: accounts exist only in the browser and device where they were created. The simple hash is for learning and is not real security.

---

## 5. How the Risk Score Works

The score follows our C program (`calculateRiskScore`), with thunderstorm and heat added from our research paper.

| Factor | Points |
|--------|--------|
| Chance of rain | rain % x 45 / 100 |
| Weather | Sunny 0, Cloudy 5, Light rain 15, Heavy rain 30, Thunderstorm 35 |
| Trip time | over 30 min: 20, over 10 min: 10, otherwise 5 |
| Transport | Walking 10, Bicycle/motorcycle 20, Covered 0 |
| Electronics | carrying: 10 |
| Temperature | 32C+: 5, 35C+: 12, 39C+: 20 |

The total is capped at 100. **70+ = High**, **40-69 = Moderate**, **below 40 = Low**.

---

## 6. Bootstrap Components Used

| Component | Where |
|-----------|-------|
| Navbar (collapses on phones) | top of every view |
| Hero | Home |
| Cards and grid (`row`, `col-*`) | Home, Dashboard |
| Accordion | About the Study |
| Forms, input group, range, select | Login, Sign Up, Dashboard |
| Alerts | messages, severe-weather alert |
| Progress bar | risk score |
| Table and badges | recent checks |

---

## 7. How to Edit

- **Brand color:** change `--sky` and `--sky-dark` at the top of the `<style>` in `index.html`.
- **Score weights:** edit the `calc()` function in the `<script>`.
- **Advice text:** edit the `recs()` function and the `CHECK` list.
- **Risk levels:** edit the `lvl()` function (70 and 40).
- Do not edit `.min.css` or `.min.js` files.

---

## 8. Test Checklist

- [ ] Opens without errors by double-clicking `index.html`
- [ ] Sign Up with a new email opens the dashboard
- [ ] Logout, then Login with the same account works
- [ ] Wrong password shows an error
- [ ] Duplicate email shows an error
- [ ] Opening `index.html#dash` while logged out goes to Login
- [ ] Check My Risk shows score, level, tips and checklist
- [ ] Recent checks update, and Clear history works
- [ ] Looks good on phone size (**F12**, then **Ctrl + Shift + M**)
- [ ] Works with the internet turned off

---

## 9. Common Mistakes and Fixes

| Problem | Likely cause | Fix |
|---------|--------------|-----|
| Page has no styling | `assets/` folder missing or wrong path | Keep `index.html` next to `assets/` |
| Icons show as empty squares | `fonts/` folder missing | Keep `bootstrap-icons.min.css` and `css/fonts/` together |
| Menu button or accordion does nothing | JavaScript not loaded | Keep `bootstrap.bundle.min.js` in `assets/js/` |
| Account disappeared | Browser data cleared or different browser | Sign up again; accounts are per browser |
| Changes do not appear | File not saved or cached | Save, then **Ctrl + F5** |

---

## 10. Limitations and Credits

- This offline version uses the weather values you enter. It does not download live forecasts.
- It is a supplementary tool and does **not** replace official advisories from PAGASA or local authorities.
- Bootstrap 5.3.3 and Bootstrap Icons 1.11.3 (MIT License)
- Research basis: Group 5 Concept Paper, SkyShield AI