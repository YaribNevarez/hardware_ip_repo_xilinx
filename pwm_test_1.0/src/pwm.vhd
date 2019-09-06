----------------------------------------------------------------------------------
-- Company: 
-- Engineer: Yarib Nevarez
-- 
-- Create Date: 
-- Design Name: PWM
-- Module Name:
-- Revision:
-- Revision
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.std_logic_arith.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

ENTITY pwm IS
    GENERIC (PWM_RESOLUTION         : INTEGER := 16;
             FREQUENCY_DIVIDER_SIZE : INTEGER := 16);
    PORT ( clk                : IN STD_LOGIC;
           reset              : IN STD_LOGIC;
           enable             : IN STD_LOGIC;
           pwm_input_value    : IN STD_LOGIC_VECTOR (PWM_RESOLUTION - 1 DOWNTO 0);
           frequency_divider  : IN STD_LOGIC_VECTOR (FREQUENCY_DIVIDER_SIZE - 1 DOWNTO 0);
           pwm_out            : OUT STD_LOGIC);
END pwm;

ARCHITECTURE Behavioral OF pwm IS

SIGNAL clk_pulse   : STD_LOGIC := '0';

BEGIN

    baud_rate_division_process: PROCESS (clk, reset, frequency_divider, clk_pulse)
        VARIABLE rate_counter   : UNSIGNED (FREQUENCY_DIVIDER_SIZE - 1 DOWNTO 0) := (others => '0');
    BEGIN
        IF falling_edge(clk) THEN
            clk_pulse <= '0';
            IF reset = '1' THEN
                rate_counter := (others => '0');
            ELSIF frequency_divider = CONV_STD_LOGIC_VECTOR(rate_counter, FREQUENCY_DIVIDER_SIZE) THEN
                rate_counter := (others => '0');
                clk_pulse <= '1';
            ELSE
                rate_counter := rate_counter + 1;
            END IF;
        END IF;
    END PROCESS;

    pwm_process : PROCESS (clk, clk_pulse, reset)
        VARIABLE pwm_counter   : UNSIGNED (PWM_RESOLUTION - 1 DOWNTO 0) := (others => '0');
    BEGIN
        IF rising_edge(clk) THEN
            IF reset = '1' THEN
                pwm_counter := (others => '0');
            ELSIF clk_pulse = '1' THEN        
                pwm_counter := pwm_counter + 1;
            END IF;
            
            IF CONV_STD_LOGIC_VECTOR(pwm_counter, PWM_RESOLUTION) < pwm_input_value THEN
                pwm_out <= enable;
            ELSE
                pwm_out <= '0';
            END IF;
        END IF;
    END PROCESS;

END Behavioral;



