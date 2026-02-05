/**
 * Perk Types
 *
 * Type definitions for perks.
 */

import type { PerkId } from '../../../types';

export type PerkCategory =
  | 'combat'
  | 'defense'
  | 'utility'
  | 'movement'
  | 'special'
  | 'gamble'
  | 'meta';

export interface PerkEffect {
  type:
    | 'damage_multiplier'
    | 'fire_rate_multiplier'
    | 'reload_speed_multiplier'
    | 'move_speed_multiplier'
    | 'max_health_multiplier'
    | 'health_regen'
    | 'xp_multiplier'
    | 'clip_size_bonus'
    | 'bonus_duration_multiplier'
    | 'pierce_bonus'
    | 'special_fire_bullets'
    | 'special_infinite_ammo_window'
    | 'special_ammo_refill_on_pickup'
    | 'special_random_weapon'
    | 'special_monster_vision'
    | 'special_shield_on_hit'
    | 'special_regression_bullets'
    | 'special_time_slow_on_hit'
    | 'special_instant_xp'
    | 'special_fatal_lottery'
    | 'special_lifeline_50_50'
    | 'special_jinxed'
    | 'special_infernal_contract'
    | 'special_grim_deal'
    | 'special_death_clock'
    | 'special_highlander'
    | 'special_plaguebearer'
    | 'special_bonus_magnet'
    | 'special_bandage'
    | 'special_gore_intensity'
    // New effect types for proper perk behaviors:
    | 'special_radioactive_aura' // Radiation damage aura around player
    | 'special_evil_eyes' // Damage bonus only when targeting enemy
    | 'special_uranium_dot' // Radiation damage over time on hit
    | 'special_poison_dot' // Poison damage over time on hit
    | 'special_dodger' // Enhanced dodge ability
    | 'special_final_revenge' // Revenge damage on death
    | 'special_veins_of_poison' // Poison damage synergy
    | 'special_toxic_avenger' // Advanced poison effects
    | 'special_ninja' // Enhanced dodging and movement
    | 'special_ion_gun_master' // Ion weapon specialist
    | 'special_angry_reloader' // Reload-based damage boost
    | 'special_stationary_reloader' // Slower reload when moving
    | 'special_man_bomb' // Periodic explosion around player
    | 'special_fire_caugh' // Fireball attack
    | 'special_living_fortress' // Defense boost when stationary
    | 'special_tough_reloader' // Damage reduction during reload
    | 'special_alternate_weapon'; // Dual weapon wielding
  value: number;
}

export interface PerkData {
  id: PerkId;
  name: string;
  description: string;
  category: PerkCategory;
  maxRank: number;
  effects: PerkEffect[];
  incompatibleWith?: PerkId[];
  requiresPerk?: PerkId;
  minLevel?: number; // Minimum player level to appear
  isRare?: boolean; // Rare perks appear less frequently
}
