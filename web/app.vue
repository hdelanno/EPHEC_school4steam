<template>
  <main class="container">
    <nav>
      <ul>
        <li><NuxtLink to="/"><strong>School4Steam - Robotics 🤖</strong></NuxtLink></li>
      </ul>
      <ul>
        <li><NuxtLink to="/">Accueil</NuxtLink></li>
        <li><NuxtLink to="/about">A propos</NuxtLink></li>
        <li><NuxtLink to="/contact">Contact</NuxtLink></li>
        <li>
          <details class="dropdown">
            <summary>
              Module
            </summary>
            <ul>
              <li selected disabled value="">Module</li>
              <li><NuxtLink to="/module1">Module 1</NuxtLink></li>
              <li><NuxtLink to="/module2">Module 2</NuxtLink></li>
              <li><NuxtLink to="/module3">Module 3</NuxtLink></li>
            </ul>
          </details>
        </li>
      </ul>
    </nav>

    <NuxtPage />
  </main>
</template>

<style>
.page-enter-active,
.page-leave-active {
  transition: all 0.4s;
}
.page-enter-from,
.page-leave-to {
  opacity: 0;
  filter: blur(1rem);
}
</style>

