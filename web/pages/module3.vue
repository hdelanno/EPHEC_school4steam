<template>
    <section>
      <p>This page will be displayed at the /module3 route.</p>
    </section>
    
    <div class="dashboard">
        <Actuator name="Moteur 1"/>
        <Actuator name="Moteur 2"/>
        <Sensor :mean="60" units="°C" />
    </div>
</template>


<style>
.dashboard {
    border-radius: 10px; 
    display: grid; 
    grid-template-columns: repeat(auto-fill, 100px); 
    grid-template-rows: repeat(auto-fill, 100px); 
    width: 100%; 
    gap: 5px;
}
</style>